#include <curl/curl.h>
#include <iostream>
#include <pybind11/pybind11.h>

size_t Callback(void* contents, size_t size, size_t nmeb, std::string* output) {
    size_t total_size = size*nmeb;
    output->append(static_cast<char*> (contents), total_size);
    return total_size;
}

std::string get(const std::string& url) {
    CURL* curl = curl_easy_init();
    std::string response;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return response;
}

int main() {
    std::string url = "https://google.com";
    std::string res = get(url);
    std::cout << res << std::endl;
}

PYBIND11_MODULE(caller, m) {
    m.def("get", &get, "function that calls http get");
}

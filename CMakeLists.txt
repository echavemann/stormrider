cmake_minimum_required(VERSION 3.11)
project(Stormrider)

include(FetchContent)
set(LIBCURL_VERSION 7.78.0)

FetchContent_Declare(
    libcurl
    URL https://curl.se/download/curl-${LIBCURL_VERSION}.tar.gz
)

FetchContent_MakeAvailable(libcurl)
add_executable(caller caller.cpp)
target_link_libraries(caller PRIVATE libcurl)

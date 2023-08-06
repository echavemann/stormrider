# Stormrider

(WIP) C++ HTTP Client.   
GET: Currently about 25% faster than requests over 1000 calls.

Recommended build command:  
`g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)`

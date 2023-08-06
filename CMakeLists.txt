cmake_minimum_required(VERSION 3.11)
project(Stormrider)


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3") #time to fly
endif()

# Add Pybind11
include(FetchContent)
set(PYBIND11_VERSION 2.8.1)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v${PYBIND11_VERSION}
)
FetchContent_MakeAvailable(pybind11)

# Add libcurl
set(LIBCURL_VERSION 7.78.0)
FetchContent_Declare(
    libcurl
    URL https://curl.se/download/curl-${LIBCURL_VERSION}.tar.gz
)
FetchContent_MakeAvailable(libcurl)

# Create a shared library for Pybind11
pybind11_add_module(caller MODULE caller.cpp)

# Link with libcurl
target_link_libraries(caller PRIVATE libcurl)


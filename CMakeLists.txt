# Build steps
cmake_minimum_required(VERSION 2.6)
project(aeon_streams)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#file(GLOB_RECURSE AEON_STREAMS_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src *.cpp)
set(AEON_STREAMS_SRC
    src/Buffer.cpp
    src/IOStream.cpp
    src/Stream.cpp
    src/FileStream.cpp
    src/MemoryStream.cpp
    )

add_library(aeon_streams STATIC ${AEON_STREAMS_SRC})

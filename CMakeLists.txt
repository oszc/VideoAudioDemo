cmake_minimum_required(VERSION 3.3)
project(VideoAudioDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp yuv.cpp pcm.cpp)
add_executable(VideoAudioDemo ${SOURCE_FILES})
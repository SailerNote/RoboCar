cmake_minimum_required(VERSION 3.0)
project(CAR_EYE)
set(CMAKE_CXX_STANDARD 11)
set(serialModel USBIOModel.cpp)
add_library(serialModel SHARED ${serialModel})
target_link_libraries(serialModel log)

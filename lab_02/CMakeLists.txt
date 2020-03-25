cmake_minimum_required(VERSION 3.0)

project(lab_02)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab_02 source.cpp)
target_link_libraries(lab_02 ${OpenCV_LIBS})
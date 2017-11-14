cmake_minimum_required(VERSION 2.8.12)

project(Exe3)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Exe3 src/main.cpp)
target_link_libraries(Exe3 ${OpenCV_LIBS})

cmake_minimum_required(VERSION 2.8)
project( Exercise_10 )
find_package( OpenCV 3 REQUIRED )
add_executable(Exercise_10 src/main.cpp )
target_link_libraries( Exercise_10 ${OpenCV_LIBS})


cmake_minimum_required(VERSION 3.10)

project(ImagePassword)
set(OpenCV_DIR C:/cygwin64/home/Ferna_x2g7ic9/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(test src/test.cpp)
add_executable(imageEncoder src/imageEncoder.cpp)

target_link_libraries(test ${OpenCV_LIBS})
target_link_libraries(imageEncoder ${OpenCV_LIBS})

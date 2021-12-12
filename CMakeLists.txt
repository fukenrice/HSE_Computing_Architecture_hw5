cmake_minimum_required(VERSION 3.16)
project(hw5)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw5 main.cpp Bee.h hive.cpp hive.h Bear.h rnd.h)
find_package (Threads)
target_link_libraries (hw5 ${CMAKE_THREAD_LIBS_INIT})
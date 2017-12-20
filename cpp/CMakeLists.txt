cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

file(GLOB All_SRC "*.h" "*.cpp")
add_executable(leetcode_cpp ${All_SRC} MaximumDepthofBinaryTree.cpp)
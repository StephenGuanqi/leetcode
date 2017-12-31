cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

file(GLOB All_SRC
		"bst/*.cpp"
		"heap/*.cpp"
		"tree/*.cpp"
		"design/*.cpp"
		"graph/*.cpp"
		"bfs/*.cpp"
		"*.cpp")
add_executable(leetcode_cpp ${All_SRC})
cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

file( GLOB LIB_SOURCES lib/*.c)
file( GLOB LIB_HEADERS lib/*.h )
add_library(csapp ${LIB_SOURCES} ${LIB_HEADERS} )

file(GLOB All_SRC
		"bst/*.cpp"
		"heap/*.cpp"
		"concurrent/*"
		"tree/*.cpp"
		"design/*.cpp"
		"graph/*.cpp"
		"bfs/*.cpp"
		"dfs/*.cpp"
		"array/*.cpp"
		"twopointers/*.cpp"
		"linkedlist/*.cpp"
		"hashtable/*.cpp"
		"stack&string/*.cpp"
		"dp/*.cpp"
		"petuum/*.cpp"
		"binarysearch/*.cpp"
		"greedy/*.cpp"
		"segmentree/*.cpp"
		"unionfind/*.cpp"
		"trie/*.cpp"
		"sweepline/*.cpp"
		"dq/*.cpp"
		"*.cpp"
		)
add_executable(leetcode_cpp ${All_SRC})
target_link_libraries(leetcode_cpp csapp)
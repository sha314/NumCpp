cmake_minimum_required(VERSION 3.0)

project(Number)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        count.h
        count.cpp
        integer.h
        integer.cpp
		float.h
		float.cpp
		fraction.h
		fraction.cpp
        main.cpp
        )
add_executable(number ${SOURCE_FILES})
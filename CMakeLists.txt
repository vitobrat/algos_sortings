cmake_minimum_required(VERSION 3.23)
project(sorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(sorting2
        main.cpp
        application.h
        application.cpp
        array.h
        array.cpp
        list.h
        list.cpp
        mergesort.h mergesort.cpp
        timsort.h timsort.cpp)

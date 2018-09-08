cmake_minimum_required(VERSION 3.12)
project(TareaCorta1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TareaCorta1 main.cpp
                Memory/Memory.h
                PagedArray/Reader.cpp
                PagedArray/Reader.h
                Memory/Memory.cpp
                PagedArray/PagedArray.cpp
                PagedArray/PagedArray.h
                Sorting/Sorting.cpp
                Sorting/Sorting.h)

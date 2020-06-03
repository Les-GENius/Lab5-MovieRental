cmake_minimum_required(VERSION 3.17)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab05
        Customer.cpp
        Customer.h
        main.cpp
        Movie.cpp
        Movie.h
        Rental.h)

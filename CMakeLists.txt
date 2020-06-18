cmake_minimum_required(VERSION 3.16.5)
project(lab05)

set(CMAKE_CXX_STANDARD 11)

include(CTest)

include(DownloadProject.cmake)
download_project(
    PROJ                googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             master
    UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

include_directories(.)

add_executable(lab05
        Customer.cpp
        Customer.h
        main.cpp
        Movie.cpp
        Movie.h
        Rental.h)

add_executable(test_lab05
        Customer.cpp
        Customer.h
        tests/CustomerTest.cpp
)

target_link_libraries(test_lab05 gtest_main gmock_main)

add_test(NAME test_lab05 COMMAND test_lab05)
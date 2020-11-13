cmake_minimum_required(VERSION 3.6)

project(DesignPatterns CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#####################################
# GTest
#####################################
enable_testing()
add_subdirectory(contrib/gtest)

#####################################
# GTest
#####################################
add_subdirectory(Patterns/Registration/Cpp)
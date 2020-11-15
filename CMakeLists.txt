cmake_minimum_required(VERSION 3.6)

project(DesignPatterns CXX)

#####################################
# GTest
#####################################
enable_testing()
add_subdirectory(contrib/gtest)

#####################################
# Project
#####################################
add_subdirectory(Patterns)
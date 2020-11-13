add_library(SubPackage_01_01 SubModule_01_01.cpp
                             Decoy.cpp)

target_include_directories(SubPackage_01_01 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(SubPackage_01_01 Base)
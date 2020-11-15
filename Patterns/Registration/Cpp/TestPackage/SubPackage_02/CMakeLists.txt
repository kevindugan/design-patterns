add_library(SubPackage_02 SubModule_02.cpp)

target_include_directories(SubPackage_02 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(SubPackage_02 PUBLIC Base)
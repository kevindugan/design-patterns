add_library(Factory ComponentBuilder.cpp)

target_include_directories(Factory INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Factory PUBLIC SubPackage_02)
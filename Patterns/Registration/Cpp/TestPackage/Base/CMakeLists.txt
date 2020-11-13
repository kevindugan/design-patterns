add_library(Base ComponentBuilder.cpp
                 ComponentRegistration.cpp)

target_include_directories(Base INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Base SubPackage_01_01)

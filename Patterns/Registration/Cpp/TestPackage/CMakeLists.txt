add_subdirectory(Base)
add_subdirectory(SubPackage_02)
add_subdirectory(ComponentFactory)

file(WRITE "${CMAKE_BINARY_DIR}/.dummyTestPackage.cpp" "int main(){return 0;}")
add_library(TestPackage "${CMAKE_BINARY_DIR}/.dummyTestPackage.cpp")

target_link_libraries(TestPackage PUBLIC Factory)
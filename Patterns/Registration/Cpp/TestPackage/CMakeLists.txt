add_subdirectory(Base)
add_subdirectory(SubPackage_01)
add_subdirectory(SubPackage_02)

file(WRITE "${CMAKE_BINARY_DIR}/.dummy.cpp" "int main(){return 0;}")
add_library(TestPackage "${CMAKE_BINARY_DIR}/.dummy.cpp")
target_link_libraries(TestPackage SubPackage_01_01)
enable_testing()

add_subdirectory(TestPackage)

add_executable(test_Registration test_RegistrationDemo.cpp)
target_link_libraries(test_Registration gtest_main TestPackage)
add_test(NAME TestRegistration COMMAND test_Registration)
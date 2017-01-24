PROJECT(PackageTest)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()
ADD_EXECUTABLE(test_util test_util.cpp)
TARGET_LINK_LIBRARIES(test_util ${CONAN_LIBS})
add_test(NAME test_util COMMAND test_util)
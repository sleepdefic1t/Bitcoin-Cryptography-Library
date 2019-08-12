
cmake_minimum_required(VERSION 3.2.2)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
	message(FATAL_ERROR
		"\n=================================================\n"
		"ERROR: Out of Source Build attempted.\n"
		"You cannot build in a source directory (or any directory with a CMakeLists.txt file).\n"
		"Please use the build directory at root.\n"
		"e.g. 'mkdir build && cd build && cmake ../ && cmake --build .'\n"
		"You should also remove CMakeCache.txt and CMakeFiles.\n"
		"=================================================\n")
endif()

project(bcl_tests C CXX)

include(CTest)
enable_testing()

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/../extern/googletest
	"${CMAKE_CURRENT_SOURCE_DIR}/../build/extern/gtest"
)

include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set (TEST_SRC
	${PROJECT_SOURCE_DIR}/Base58CheckTest.cpp
	${PROJECT_SOURCE_DIR}/CurvePointTest.cpp
	${PROJECT_SOURCE_DIR}/EcdsaTest.cpp
	${PROJECT_SOURCE_DIR}/ExtendedPrivateKeyTest.cpp
	${PROJECT_SOURCE_DIR}/FieldIntTest.cpp
	${PROJECT_SOURCE_DIR}/Keccak256Test.cpp
	${PROJECT_SOURCE_DIR}/Ripemd160Test.cpp
	${PROJECT_SOURCE_DIR}/Sha256Test.cpp
	${PROJECT_SOURCE_DIR}/Sha256HashTest.cpp
	${PROJECT_SOURCE_DIR}/Sha512Test.cpp
	${PROJECT_SOURCE_DIR}/Uint256Test.cpp
)

find_library(bcl_tests PUBLIC)

add_executable(bcl_tests ${TEST_SRC})

target_link_libraries(bcl_tests bcl gtest gtest_main)

add_test(NAME test COMMAND bcl_tests)

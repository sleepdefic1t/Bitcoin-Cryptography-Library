
cmake_minimum_required(VERSION 3.2)

project(${PROJECT_NAME}_tests C CXX)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

# ------------------------------------------------------------------------------
# External Libraries
# ------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/GTest.cmake)

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Link the directories to be included
# ------------------------------------------------------------------------------

include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# BCL Test Source
# ------------------------------------------------------------------------------

set (BCL_TEST_SOURCE
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

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Link BCL to the Test Libraries
# ------------------------------------------------------------------------------

find_library(bcl_tests PUBLIC)

add_executable(bcl_tests ${BCL_TEST_SOURCE})

target_link_libraries(bcl_tests bcl gtest gtest_main)

add_test(NAME test COMMAND bcl_tests)

# ------------------------------------------------------------------------------


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

project(bcl C CXX)

set(BCL_SRC
	Base58Check.cpp
	CurvePoint.cpp
	Ecdsa.cpp
	# EcdsaOpCount.cpp
	ExtendedPrivateKey.cpp
	FieldInt.cpp
	Keccak256.cpp
	Ripemd160.cpp
	Sha256.cpp
	Sha256Hash.cpp
	Sha512.cpp
	Uint256.cpp
	Utils.cpp
)

add_library(${PROJECT_NAME} STATIC ${BCL_SRC})

set(BCL_BUILD_INCLUDE_DIRS ${PROJECT_SOURCE_DIR})

include_directories(${BCL_BUILD_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} PUBLIC ${BCL_BUILD_INCLUDE_DIRS} )

if (MSVC)
	target_link_libraries(${PROJECT_NAME} PUBLIC crypt32)
endif()

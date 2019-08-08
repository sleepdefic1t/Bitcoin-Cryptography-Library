cmake_minimum_required(VERSION 3.2.2)

project(BCL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/build)

if (MSVC)
	add_definitions(
		-D_CRT_SECURE_NO_WARNINGS
		-D_SCL_SECURE_NO_WARNINGS
		-DNOMINMAX
	)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

# clone submodules
execute_process(
	COMMAND git submodule update --init --recursive
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
	message(FATAL_ERROR
		"\n=================================================\n"
		"ERROR: Out of Source Build attempted.\n"
		"You cannot build in a source directory (or any directory with a CMakeLists.txt file).\n"
		"Please use the build directory at root.\n"
		"e.g. 'cd bcl/build && cmake ../ && cmake --build .'\n"
		"You should also remove CMakeCache.txt and CMakeFiles.\n"
		"=================================================\n")
endif()

add_subdirectory(src)
add_subdirectory(test)

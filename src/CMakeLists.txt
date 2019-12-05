
cmake_minimum_required(VERSION 3.2.2)

project(bcl C CXX)

# ------------------------------------------------------------------------------
# BCL Source
# ------------------------------------------------------------------------------

set(BCL_SOURCE
	Base58Check.cpp
	CurvePoint.cpp
	Ecdsa.cpp
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

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Add the Source Files to the Library
# ------------------------------------------------------------------------------

add_library(${PROJECT_NAME} SHARED STATIC ${BCL_SOURCE})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Set the Include Folders
# ------------------------------------------------------------------------------

set(BCL_BUILD_INCLUDE_DIRS ${PROJECT_SOURCE_DIR})

include_directories(${BCL_BUILD_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} PUBLIC ${BCL_BUILD_INCLUDE_DIRS} )

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Windows: Link to `crypt32`
# ------------------------------------------------------------------------------

if (MSVC)
	target_link_libraries(${PROJECT_NAME} PUBLIC crypt32)
endif()

# ------------------------------------------------------------------------------

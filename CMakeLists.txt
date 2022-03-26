cmake_minimum_required(VERSION 3.18)

project(basic)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG(-fvisibility-inlines-hidden COMPILER_HAS_VISIBILITY_INLINE_HIDDEN)
CHECK_CXX_COMPILER_FLAG(-fvisibility=hidden COMPILER_HAS_VISIBILITY_HIDDEN)

set(CMAKE_CXX_STANDARD 20)

if (${COMPILER_HAS_VISIBILITY_INLINE_HIDDEN})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
endif()

if (${COMPILER_HAS_VISIBILITY_HIDDEN})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
endif()

option(USE_BISON "run bison" TRUE)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(Boost_USE_MULTITHREADED      OFF)
set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.77 COMPONENTS date_time filesystem regex system program_options)

if(Boost_FOUND)
	add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)
    include_directories(${Boost_INCLUDE_DIRS})
    link_libraries(${Boost_LIBRARIES})
else()
	message(FATAL_ERROR "boost not found! please set BOOST_ROOT if you install boost into non-standard location")
endif()

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_subdirectory(compiler)
add_subdirectory(brt)
add_subdirectory(test)

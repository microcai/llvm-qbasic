cmake_minimum_required(VERSION 2.8)

project(basic)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG(-fvisibility-inlines-hidden COMPILER_HAS_VISIBILITY_INLINE_HIDDEN)
CHECK_CXX_COMPILER_FLAG(-fvisibility=hidden COMPILER_HAS_VISIBILITY_HIDDEN)
CHECK_CXX_COMPILER_FLAG(-std=c++11 LIBCXX_HAS_STDCXX11_FLAG)


if (${COMPILER_HAS_VISIBILITY_INLINE_HIDDEN})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
endif()

if (${COMPILER_HAS_VISIBILITY_HIDDEN})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
endif()

if (NOT MSVC)
	if(LIBCXX_HAS_STDCXX11_FLAG)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	else()
		CHECK_CXX_COMPILER_FLAG(-std=c++0x LIBCXX_HAS_STDCXX0X_FLAG)
		if(LIBCXX_HAS_STDCXX0X_FLAG)
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
		else()
			if(NOT CMAKE_CXX_COMPILER MATCHES "icc")
				message(FATAL "need at least gcc 4.4.7 or clang 3.2")
			endif(NOT CMAKE_CXX_COMPILER MATCHES "icc")
		endif()
	endif(LIBCXX_HAS_STDCXX11_FLAG)
	# endif() # if(NOT CMAKE_CXX_COMPILER MATCHES "icc")
endif(NOT MSVC)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(Boost_USE_MULTITHREADED      OFF)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_STATIC_RUNTIME    ON)

find_package(Boost 1.46 COMPONENTS date_time filesystem regex system program_options)

if(Boost_FOUND)
	add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)
    include_directories(${Boost_INCLUDE_DIRS})
    link_libraries(${Boost_LIBRARIES})
else()
	message(FATAL_ERROR "boost not found! please set BOOST_ROOT if you install boost into non-standard location")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(compiler)
add_subdirectory(brt)
add_subdirectory(test)

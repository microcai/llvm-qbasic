cmake_minimum_required(VERSION 2.8)

project(basic)

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
endif()

add_subdirectory(brt)
add_subdirectory(compiler)
add_subdirectory(include)
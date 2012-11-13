cmake_minimum_required(VERSION 2.8)

project(basic)
include(${PROJECT_SOURCE_DIR}/FindBISON.cmake)
include(${PROJECT_SOURCE_DIR}/FindFLEX.cmake)

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(Boost_USE_MULTITHREADED      OFF)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_STATIC_RUNTIME    ON)

add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)

find_package(Boost 1.46 COMPONENTS date_time filesystem regex system program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_libraries(${Boost_LIBRARIES})
endif()

BISON_TARGET(QBParse parser.ypp ${PROJECT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(QBLex qblex.ll ${PROJECT_BINARY_DIR}/qblex.cpp)

ADD_FLEX_BISON_DEPENDENCY(QBLex QBParse)
include_directories(
    ${PROJECT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}
)

add_executable(llvm-qbc ast.cpp main.cpp
	${BISON_QBParse_OUTPUTS} ${FLEX_QBLex_OUTPUTS}
)

install(TARGETS llvm-qbc RUNTIME DESTINATION bin)

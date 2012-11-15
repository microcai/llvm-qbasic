cmake_minimum_required(VERSION 2.8)

include(${PROJECT_SOURCE_DIR}/cmake/FindBISON.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindFLEX.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindLLVM.cmake)

if(NOT Boost_FOUND)
	set(Boost_USE_MULTITHREADED      OFF)
	set(Boost_USE_STATIC_LIBS        ON)
	set(Boost_USE_STATIC_RUNTIME    ON)
	find_package(Boost 1.46 COMPONENTS date_time filesystem regex system program_options)
	if(Boost_FOUND)
		add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)
		include_directories(${Boost_INCLUDE_DIRS})
		link_libraries(${Boost_LIBRARIES})
	endif()
endif()

if( USE_BISON )
	BISON_TARGET(QBParse parser.ypp ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp)
	FLEX_TARGET(QBLex qblex.ll ${CMAKE_CURRENT_SOURCE_DIR}/qblex.cpp)

	ADD_FLEX_BISON_DEPENDENCY(QBLex QBParse)

else()
	SET(BISON_QBParse_OUTPUTS parser.cpp)
	SET(FLEX_QBLex_OUTPUTS qblex.cpp)
endif()


link_directories(${LLVM_LIBDIR})
link_libraries("${LLVM_LIBRARIES}")

SET(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} ${LLVM_CPPFLAGS} ")

add_executable(llvm-qbc ast.cpp llvmwrapper.cpp typeast.cpp codegen.cpp
	${BISON_QBParse_OUTPUTS} ${FLEX_QBLex_OUTPUTS}
	main.cpp 
)

install(TARGETS llvm-qbc RUNTIME DESTINATION bin)

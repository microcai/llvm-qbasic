cmake_minimum_required(VERSION 3.18)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if(NOT Boost_FOUND)
	set(Boost_USE_MULTITHREADED      OFF)
	set(Boost_USE_STATIC_LIBS        ON)
	set(Boost_USE_STATIC_RUNTIME    ON)
	find_package(Boost 1.46 COMPONENTS date_time filesystem regex system program_options)
	if(Boost_FOUND)
		add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)
		include_directories(${Boost_INCLUDE_DIRS})
		link_libraries(${Boost_LIBRARIES})
	else()
		message(FATAL_ERROR
			"boost not found! please set BOOST_ROOT if you install boost into non-standard location")
	endif()
endif()

if( USE_BISON )
	BISON_TARGET(QBParse parser.ypp ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp)
	FLEX_TARGET(QBLex qblex.ll ${CMAKE_CURRENT_SOURCE_DIR}/qblex.cpp)

	ADD_FLEX_BISON_DEPENDENCY(QBLex QBParse)

else()
	SET(BISON_QBParse_OUTPUTS parser.cpp)
	SET(FLEX_QBLex_OUTPUTS qblex.cpp)
	message(AUTHOR_WARNING "set -DUSE_BISON=1 on cmake command line if you want to build parser from bison rules")
endif()


# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support)

# Link against LLVM libraries
message(STATUS "Using LLVM libs: ${llvm_libs}")

SET(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} ${LLVM_CPPFLAGS} ")

add_executable(llvm-qbc type.cpp ast.cpp operator.cpp codegen.cpp llvmwrapper.cpp
	${BISON_QBParse_OUTPUTS} ${FLEX_QBLex_OUTPUTS}
	main.cpp
)

target_include_directories(llvm-qbc PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(llvm-qbc PRIVATE ${LLVM_DEFINITIONS})
target_link_libraries(llvm-qbc LLVM ${llvm_libs})
#llvm_config(llvm-qbc support tablegen)

install(TARGETS llvm-qbc RUNTIME DESTINATION bin)

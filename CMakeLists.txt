project(basic)

add_executable(basic ast.cpp main.cpp)

install(TARGETS basic RUNTIME DESTINATION bin)


include_directories(${PROJECT_SOURCE_DIR}/compiler)

add_library(brt print.cpp mm.cpp qbarray.cpp)

set_target_properties(brt PROPERTIES POSITION_INDEPENDENT_CODE ON)

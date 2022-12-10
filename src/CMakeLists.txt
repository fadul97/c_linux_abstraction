project(lal)

add_library(lal_platform lal_window.c lal_input.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

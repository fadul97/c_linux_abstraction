cmake_minimum_required(VERSION 3.16)
project(lal)

#set(CMAKE_VERBOSE_MAKEFILE on )

if(CMAKE_COMPILER_IS_GNUCXX)
	add_compile_options(-pedantic -Wall -Wextra 
		-Wunused-parameter -Wunused-variable -Wcast-align -Wcast-qual 
		-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op 
		-Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls 
		-Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wswitch-default 
		-Wundef -Werror -Wno-unused)
endif()

add_executable(lal main.c)

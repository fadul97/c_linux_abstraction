project(lal)

if(CMAKE_COMPILER_IS_GNUCXX)
	add_compile_options(-pedantic -Wall -Wextra 
		-Wunused-parameter -Wunused-variable -Wcast-align -Wcast-qual 
		-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op 
		-Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls 
		-Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wswitch-default 
		-Wundef -Werror -Wno-unused)
endif()

add_executable(lal main.c)

if(UNIX)
	target_link_libraries(lal -lX11)
endif()

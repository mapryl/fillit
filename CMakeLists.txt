cmake_minimum_required(VERSION 3.13)
project(Fillit_final C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Fillit_final
		create_list.c
		field.c
		field.h
		find_solution.c
		find_solution.h
		tetr_list.h
		tetromino.c
		tetromino.h
		validation.c
		validation.h
		w_h_counter.c)

cmake_minimum_required(VERSION 3.13)
project(Fillit_final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Fillit_final
		check_figure.c
		ConsoleApplication1.c
		create_list.c
		create_tetrimino.c
		ft_list.h
		h_count.c
		main.c
		text.txt
		w_count.c
		сheck_file.c)

#ifndef FT_LIST_H
#   define FT_LIST_H

//#   include <unistd.h>
#include <io.h>
#   include <stdio.h>
#   include <stdlib.h>
//#   include "Libft/includes/libft.h"
#   include <fcntl.h>

#   define BUFF_SIZE 26

typedef struct tetromin
{
	char* form;
	int width;
	int height;
} s_tetromin;

typedef struct tetr_list
{
	s_tetromin tetromin_data;
	struct tetr_list* next;
} s_tetr_list;

typedef struct
{
	int size;
	char** field;
} s_field;

void find_solution(const s_tetr_list* tetr_arr, int size_arr);
s_tetromin* create_tetrimino(char* tetromin);
s_tetr_list* create_list(s_tetromin* head, struct tetr_arr* next);
int     setup(char** argv);
int     check_file(char* line);
int     check_figure(char* line);
void w_count(char* line, int *w_arr);
void h_count(char* line, int *h_arr);

#endif

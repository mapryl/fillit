#ifndef TETROMINO_H
#define TETROMINO_H

#include "field.h"
typedef struct tetromin
{
	char* form;
	int width;
	int height;
} s_tetromin;

s_tetromin* create_tetrimino(char* tetromin, int figure_counter);
int		tetr_can_insert(const s_tetromin* tetromin, int y, int x, const s_field* field);
void tetr_insert(const s_tetromin* tetromin, int y, int x, s_field* field);
void	tetr_erase(const s_tetromin* tetromin, int y, int x, s_field* field);
void	w_count(char* line, int* w_arr);
void	h_count(char* line, int* h_arr);

#endif // !TETROMINO_H

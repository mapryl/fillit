#ifndef TETR_LIST_H
#   define TETR_LIST_H

#include "tetromino.h"

typedef struct tetr_list
{
	s_tetromin tetromin_data;
	struct tetr_list* next;
} s_tetr_list;

s_tetr_list* create_list(s_tetromin* head, s_tetr_list* next);

#endif
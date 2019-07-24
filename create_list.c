#include "ft_list.h"

s_tetr_list* create_list(s_tetromin* head, s_tetr_list* next)
{
	s_tetr_list* tmp;

	tmp = (s_tetr_list*)malloc(sizeof(s_tetr_list));
	tmp->tetromin_data = *head;
	tmp->next = next;

	return(tmp);
}
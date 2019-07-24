#include "ft_list.h"
/*
void    print_node(s_tetromin *node);
s_tetromin   *create_tetrimino(char *tetromin, int width, int height);
s_tetr_arr *create_list(s_tetromin *head, struct tetr_arr *next);
int main(void)
{
    print_node(create_list(create_tetrimino("...#\n...#\n...#\n...#",2,1)), NULL);
    return(0);
}
void    print_node(s_tetr_arr *node)
{
    if(node)
    {
        printf("%s\n", node->form);
        printf("%d\n", node->width);
        printf("%d\n", node->height);
        //printf("%s\n", node->next);
    }
}
s_tetr_arr *create_list(s_tetromin *head, struct tetr_arr *next)
{
	s_tetr_arr *tmp;
	tmp = (s_tetr_arr *)malloc(sizeof(s_tetr_arr));
	tmp->tetromin_data = *head;
	tmp->next = next;
	return(tmp);
}
*/
/////////////////////////////////////////////////////////////////////

#include <string.h>

s_tetromin   *create_tetrimino(char *tetromin, int width, int height)
{
    s_tetromin *tetromin_head;

    tetromin_head = (s_tetromin *)malloc(sizeof(s_tetromin));

	tetromin_head->form = _strdup(tetromin);
    tetromin_head->width = width;
    tetromin_head->height = height;

    return(tetromin_head);
}
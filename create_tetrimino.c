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

char* to_letter(char* line, int w_arr[], int width, int h_arr[], int hight)
{
	int i = 0;
	int j = 0;
	char* new_line = (char*)malloc(sizeof(char) * width * hight + 1);
	if (new_line == NULL)
		return NULL;
	memset(new_line, '\0', width * hight + 1);

	while (line[i])
	{
		if ((line[i] == '.' && w_arr[i % 5] == 1 && h_arr[i / 5] == 1) || line[i] == '#')
		{
			new_line[j] = line[i];
			j++;
		}
		i++;
	}
	return new_line;
}

s_tetromin   *create_tetrimino(char *tetromin, int figure_counter)
{
    s_tetromin *tetromin_head;

    tetromin_head = (s_tetromin *)malloc(sizeof(s_tetromin));

	int w_arr[4] = { 0 };
	int h_arr[4] = { 0 };
	w_count(tetromin, w_arr);
	h_count(tetromin, h_arr);
	int i = 0;
	int width = 0;
	int hight = 0;
	while (i < 5)
	{
		if (w_arr[i] == 1)
			width++;
		if (h_arr[i] == 1)
			hight++;
		i++;
	}
	tetromin = to_letter(tetromin, w_arr, width, h_arr, hight);
	i = 0;
	while (tetromin[i])
	{
		if (tetromin[i] == '#')
			tetromin[i] = 'A' + figure_counter;
		i++;
	}
	tetromin_head->form = tetromin;
    tetromin_head->width = width;
    tetromin_head->height = hight;

    return(tetromin_head);
}
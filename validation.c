#include "validation.h"
#include "tetromino.h"
#include "tetr_list.h"
#include "find_solution.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int             check_file(char* line)
{
	int i = 0; //�������
	int hcount = 0; //#
	int ncount = 0; //\n
	int dcount = 0; //.

	while (line[i] != '\0')
	{
		if (line[i] == '#')
			hcount++;
		else if (line[i] == '.')
			dcount++;
		else if (line[i] == '\n')
			ncount++;
		i++;
	}
	if (hcount != 4 || dcount != 12 || ncount > 5) //����� �������� ������ �������� � ���� ...
		return (0);
	return (1);
}

int check_figure(char* line)
{
	int touch = 0; //���������� �������
	int hcount = 0; //���������� ����������� ������
	int i = 0; //�������
	while (hcount < 4)
	{
		while (line[i] != '#')
			i++;
		if (line[i + 1] == '#')
			touch++;
		if (line[i - 1] == '#')
			touch++;
		if (line[i + 5] == '#')
			touch++;
		if (line[i - 5] == '#')
			touch++;
		hcount++;
		i++;
	}
	printf("Number of touches: %d\n", touch); //����� "�������"
	if (touch == 6 || touch == 8)
		return (1);
	else
		return (0);
}

int setup(char** argv)
{
	int fd;
	int rd;
	char *line;
	int figure_counter = 0;
	t_tetromin* tetromin_head;
	t_tetr_list* first_tetr_arr = 0;
	t_tetr_list* current_tetr = 0;
	t_tetr_list* previous_tetr = 0;

	line = ((char*)malloc(sizeof(char) * BUFF_SIZE + 1));
	fd = open(argv[1], O_RDONLY);
	if (fd <= -1 /*|| fd == -1*/)
		return -1;
	while ((rd = read(fd, line, BUFF_SIZE)) > 0)
	{
		line[rd] = '\0';
		//�������� ���� � ������ �� ����������
		int i = check_file(line); //��������� ���� �� ����������
		if (i != 1)
		{
			printf("This part of file is NOT VALID:\n");
			printf("%s\n", line);
			printf("Abort.\n");
			return -1;
		}
		printf("This part of file is VALID (1Y/0N): %d. Continue.\n", i);

		i = check_figure(line); //��������� ������ �� ����������
		if (i != 1)
		{
			printf("This figure is NOT VALID. Number of touches is good (1Y/0N): %d\n.", i);
			printf("%s\n", line);
			printf("Abort.\n");
			return -1;
		}
		printf("This figure is VALID. Number of touches is good (1Y/0N): %d. Continue.\n", i);
		printf("%s\n", line);
		if (figure_counter == 0)
		{
			tetromin_head = create_tetrimino(line, figure_counter);
			first_tetr_arr = create_list(tetromin_head, NULL);
			previous_tetr = first_tetr_arr;
		}
		else
		{
			current_tetr = create_list(create_tetrimino(line, figure_counter), NULL);
			previous_tetr->next = current_tetr;
			previous_tetr = current_tetr;
		}
		figure_counter++;
	}
	printf("File and figures inside are valid\n\n");
	printf("%d\n", figure_counter);
	find_solution(first_tetr_arr, figure_counter); //!!!
	return (1);
}


int main(int argc, char** argv)
{
	{
		if (argc == 2) {
			if (setup(argv) == 1) {
				//	printf("begin");
				//char a = 'a';
				//printf("%c", a);


				/*s_tetromin tetromin1 = {"AAAA", 1, 4};
				s_tetromin tetromin2 = {"BBBB", 4, 1};
				s_tetromin tetromin3 = {"CCC..C", 3, 2};
				s_tetromin tetromin4 = {".DDDD.", 3, 2};
				s_tetromin tetromin5 = {"EEEE", 2, 2};
				s_tetromin tetromin6 = {"FF..FF", 3, 2};
				s_tetromin tetromin7 = {"GG.G.G", 2, 3};
				s_tetromin tetromin8 = {"HHH.H.", 3, 2};
				s_tetr_arr tetr8 = {tetromin8, NULL};
				s_tetr_arr tetr7 = {tetromin7, &tetr8};
				s_tetr_arr tetr6 = {tetromin6, &tetr7};
				s_tetr_arr tetr5 = {tetromin5, &tetr6};
				s_tetr_arr tetr4 = {tetromin4, &tetr5};
				s_tetr_arr tetr3 = {tetromin3, &tetr4};
				s_tetr_arr tetr2 = {tetromin2, &tetr3};
				s_tetr_arr tetr1 = {tetromin1, &tetr2};
				find_solution(&tetr1, 8);*/

			}

		}
		else {
			printf("Invalid number of arguments (more/less than 2)\n");
			return (-1);
		}
		return (0);
	}
}
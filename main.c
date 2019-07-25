#include "ft_list.h"
#include <fcntl.h>
#include <unistd.h>

int setup(char** argv)
{
	int fd = 0;
	int rd;
	char *line;
	int figure_counter = 0;
	s_tetromin* tetromin_head;
	s_tetr_list* first_tetr_arr = 0;
	s_tetr_list* current_tetr = 0;
	s_tetr_list* previous_tetr = 0;


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
			setup(argv);
		}
		else {
			printf("Invalid number of arguments (more/less than 2)\n");
			return (-1);
		}
		return (0);
	}
}
#include <stdio.h> //������ ������ � printf ��� ����������

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
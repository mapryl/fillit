/*#include <stdio.h>
int h_count(char *line);
int main(void)
{
	printf("%d\n", h_count("..#..\n.#..\n.##.\n...."));
	return (0);
}
*/

int h_count(char* line)
{
	int hcount = 0;
	//int hashmax = 0;
	int i = 0;

	while (line[i] != '\0')
	{
		while (line[i] != '#')
		{
			if (line[i] == '\0')
				return (hcount);
			i++;
		}
		while (line[i] != '\n')
		{
			if (line[i] == '\0')
				return (hcount);
			i++;
		}
		if (line[i] == '\n')
			hcount++;
		if (line[i] == '\0')
			return(hcount);
		i++;
	}
	return(hcount);
}
#include "ft_list.h"
//#include <stdio.h>

/*void wh_count(char *line);
int main(void)
{
	printf("%d\n", w_count("...#\n...#\n...#\n...#"));
	return (0);
}
*/

int w_count(char* line)
{
	int wcount = 0;
	int wcount_max = 0;
	int hcount = 1;
	int i = 0;

	while (line[i])
	{
		while (line[i] != '#')
		{
			if (line[i] == '\n')
				hcount++;
			if (line[i] == '\0')
				return (hcount);
			i++;
		}
		if (line[i] == '#')
			wcount++;
		i++;
		if (line[i] == '\n')
		{
			wcount_max = wcount;
			wcount = 0;
		}
	}
	return(wcount_max);
}
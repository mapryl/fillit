void h_count(char* line, int *h_arr)
{
	//int h_arr[4] = { 0 };
	int i = 0;

	while (line[i])
	{
		if (line[i] == '#')
			h_arr[i / 5] = 1;
		i++;
	}
	//return h_arr;
}
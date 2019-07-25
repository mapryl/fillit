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
	if (hcount != 4 || dcount != 12 || ncount > 5)
		return (0);
	return (1);
}
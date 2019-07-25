#include "field.h"
#include <stdlib.h>
#include <io.h> //DELETE
#include <string.h> //DELETE

//#include <unistd.h>

char* create_dot_str(int size)
{
	char* str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < size)
			memcpy(str + i++, ".", 2);
	}
	return (str);
}

void	field_create(s_field* field, int size)
{
	int		i;

	i = 0;
	field->field = (char**)malloc(sizeof(char*) * (size + 1));
	if (!(field->field))
		return;
	while (i < size)
	{
		field->field[i] = create_dot_str(size);
		i++;
	}
	field->field[size] = "";
	field->size = size;
}

void	field_delete(s_field* field)
{
	int		i;

	i = 0;
	while (i < field->size)
		free(field->field[i++]);
	free(field->field);
}

void	field_resize(s_field* field, int size)
{
	field_delete(field);
	field_create(field, size);
}

void	field_print(const s_field* field)
{
	int		i;
	int		j;

	i = 0;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
			_write(1, &field->field[i][j++], 1);
		_write(1, "\n", 1);
		i++;
	}
}

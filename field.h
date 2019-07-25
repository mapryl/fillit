#ifndef FIELD_H
#define FIELD_H

typedef struct
{
	int size;
	char** field;
} s_field;

void	field_create(s_field* field, int size);
void	field_delete(s_field* field);
void	field_resize(s_field* field, int size);
void	field_print(const s_field* field);


#endif // !FIELD_H

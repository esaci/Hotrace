#include "hotrace.h"

void	set_db(t_Page **db)
{
	int i;

	i = 0;
	while(i++ < 10008)
		db[i] = NULL;
}

int	hashing_function(t_Page *tmp)
{
	static size_t	count = 0;
	(void) tmp;

	return(count++);	
}

int	result_function(char *tmp)
{
	static size_t	count = 0;
	(void) tmp;

	return (count++);
}

int	main( void )
{
	t_Page			**db;
	t_Page			*tmp;
	unsigned int	count;
	char			**str;

	db = malloc(sizeof(*db) * 10008);
	if (!db)
		return (1);
	set_db(db);
	tmp = malloc(sizeof(t_Page) * 2);
	while (get_next_line(0, &tmp->keyword) > 0)
	{
		if (!tmp->keyword || tmp->keyword[0] == '\n')
			break;
		if (get_next_line(0, &tmp->value) <= 0)
			break;
		count = hashing_function(tmp);
		if (db[count])
			db[count]->Collision = tmp;
		else
			db[count] = tmp;
		tmp = malloc(sizeof(t_Page) * 2);
	}
	str = NULL;
	while (get_next_line(0, str) > 0)
	{
		count =  result_function(*str);
		write(0, db[count]->value, ft_strlen(db[count]->value));
		free(*str);
	}
	return (0);
}
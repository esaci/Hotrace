#include "hotrace.h"

void	set_db(t_Page **db)
{
	size_t i;

	i = 0;
	while(i++ < DB_TAILLE)
		db[i] = NULL;
}

size_t	hashing_function(t_Page *tmp)
{
	static size_t	count = 0;
	(void) tmp;

	return(count++);	
}

size_t	result_function(char *tmp)
{
	static size_t	count = 0;
	(void) tmp;

	return (count++);
}

t_Page	*Page_init(void)
{
	t_Page	*tmp;

	tmp = malloc(sizeof(t_Page) * 2);
	tmp->value = NULL;
	tmp->keyword = NULL;
	tmp->Collision = NULL;
	return (tmp);
}

int	main( void )
{
	t_Page			**db;
	t_Page			*tmp;
	size_t			count;
	char			**str;

	db = malloc(sizeof(t_db) * (2));
	if (!db)
		return (1);
	set_db(db);
	tmp = Page_init();
	while (get_next_line(0, &tmp->keyword) > 0)
	{
		if (!tmp->keyword || tmp->keyword[0] == '\n')
			break;
		if (get_next_line(0, &tmp->value) <= 0 || tmp->value[0] == '\n')
			break;
		count = hashing_function(tmp);
		if (db[count])
			db[count]->Collision = tmp;
		else
			db[count] = tmp;
		tmp = Page_init();
	}
	str = NULL;
	while (get_next_line(0, str) > 0)
	{
		count =  result_function(*str);
		if (db[count])
			write(0, db[count]->value, ft_strlen(db[count]->value));
		else
		{
			write(0, *str, ft_strlen(*str));

		}
		free(*str);
	}
	count = 0;
	while (count < DB_TAILLE)
	{
		if (db[count])
		{
			if (db[count]->value)
				free(db[count]->value);
			if (db[count]->keyword)
				free(db[count]->value);
			if (db[count]->Collision)
				free(db[count]->Collision);
			free(db[count]);
		}
		count++;
	}
	free(db);
	return (0);
}
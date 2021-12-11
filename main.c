#include "hotrace.h"

int	main( void )
{
	t_db			*db;
	t_Page			*tmp;
	size_t			count;
	char			**str;
	t_db			*dmp;

	db = NULL;
	if (set_db(&db))
		return (1);
	tmp = Page_init();
	while (get_next_line(0, &tmp->keyword) > 0)
	{
		if (!tmp->keyword || tmp->keyword[0] == '\n')
			break;
		if (get_next_line(0, &tmp->value) <= 0 || tmp->value[0] == '\n')
			break;
		count = hashing_function(tmp);
		if (set_db_to_count(db, count, tmp));
			return (1);
		tmp = Page_init();
	}
	str = NULL;
	while (get_next_line(0, str) > 0)
	{
		if (!str)
			break;
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
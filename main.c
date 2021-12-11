#include "hotrace.h"

int	main( void )
{
	t_Page			**db;
	t_Page			*tmp;
	size_t			count;
	char			*str;

	db = malloc(sizeof(*db) * (DB_TAILLE + 1));
	if (!db)
		return (1);
	set_db(db);
	write(1, "db malloced\n", 13);
	tmp = Page_init();
	while (get_next_line(0, &(tmp->keyword)) > 0)
	{
		if (!tmp->keyword || tmp->keyword[0] == '\0')
		{
			write(1, "Line Break found\n", 18);
			break;
		}
		if (get_next_line(0, &(tmp->value)) <= 0 || !tmp->value || tmp->value[0] == '\0')
		{
			write(1, "Line Break found\n", 18);
			break;
		}
		count = hashing_function(tmp);
		if (db[count])
			db[count]->Collision = tmp;
		else
			db[count] = tmp;
		tmp = Page_init();
	}
	unset_Page(tmp);
	str = NULL;
	write(1, "Recherche ....\n", 16);
	while (get_next_line(0, &str) > 0)
	{
		count = result_function(str);
		if (db[count])
		{
			write(1, db[count]->value, ft_strlen(db[count]->value));
			write(1, "\n", 1);
		}
		else
		{
			write(1, str, ft_strlen(str));
			write(1, ": Not found.\n", 14);
		}
		free(str);
	}
	if (str)
		free(str);
	count = 0;
	while (count < DB_TAILLE)
	{
		if (db[count])
			unset_Page(db[count]);
		count++;
	}
	free(db);
	return (0);
}
#include "hotrace.h"

int	main( void )
{

	t_Page			**db;
	t_Page			*dmp;
	t_Page			*tmp;
	size_t			count;
	char			*str;

	db = malloc(sizeof(*db) * (DB_TAILLE + 1));
	if (!db)
		return (1);
	set_db(db);
	write(1, "db Ready\n", 9);
	tmp = Page_init();
	while (get_next_line(0, &(tmp->keyword)) > 0)
	{
		if (!tmp->keyword || tmp->keyword[0] == '\0')
			break;
		if (get_next_line(0, &(tmp->value)) <= 0 || !tmp->value || tmp->value[0] == '\0')
			break;

		count = hashing_function(tmp->keyword);
		if (db[count])
		{
			dmp = db[count];
			while (dmp->Collision)
				dmp = dmp->Collision;
			dmp->Collision = tmp;
		}
		else
			db[count] = tmp;
		tmp = Page_init();
	}
	unset_Page(tmp);
	str = NULL;
	write(1, "Recherche ....\n", 15);
	while (get_next_line(0, &str) > 0)
	{

		count = hashing_function(str);
		if (db[count])
		{
			write(1, db[count]->value, ft_strlen(db[count]->value));
			write(1, "\n", 1);
		}
		else
		{
			write(1, str, ft_strlen(str));
			write(1, ": Not found.\n", 13);
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
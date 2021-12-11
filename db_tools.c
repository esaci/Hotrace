#include "hotrace.h"

int	set_db(t_db **db)
{
	*db = malloc(sizeof(t_db) * (2));
	if (!db)
		return (1);
	(*db)->Page = NULL;
	(*db)->next = NULL;
	return (0);
}

int	set_db_to_count(t_db *db, size_t count)
{
	size_t	parse;
	t_db	*tmp;

	tmp = db;
	parse = 0;
	while (parse < count)
	{
		if (!db->next)
		{
			if (set_db(&(db->next)))
				return (1);
		}
	}
	return (0);
}
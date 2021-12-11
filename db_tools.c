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

int	set_db_to_count(t_db *db, size_t count, t_Page *tmp)
{
	size_t	parse;

	parse = 0;
	while (parse < count)
	{
		if (!db->next)
		{
			if (set_db(&(db->next)))
				return (1);
		}
		db = db->next;
	}
	if (!db->next)
	{
		set_db(&(db->next));
		db = db->next;
	}
	else
	{
		set_db(&(db->Collision));
		db = db->Collision;
	}
	db->Page = tmp;
	return (0);
}

t_db	*get_db_with_count(t_db	*db, size_t	count)
{
	size_t	tmp;

	tmp = 0;
	while (tmp < count)
	{
		if (!db)
			return (NULL);
		db = db->next;
	}
	return (db);
}

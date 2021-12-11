#include "hotrace.h"

void	set_db(t_Page **db)
{
	size_t i;

	i = 0;
	while(i < DB_TAILLE)
		db[i++] = NULL;
}
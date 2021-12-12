#include "hotrace.h"

size_t	hashing_function(char *str)
{
	size_t length;
	size_t hash	=	5381;
	size_t i		= 0;

	length = ft_strlen(str);
	for (i = 0; i < length; ++str, ++i)
	{
		hash = ((hash << 5) + hash) + (*str);
	}
	hash = hash % DB_TAILLE;
	return hash;
}

size_t	result_function(char *tmp)
{
	static size_t	count = 0;
	(void) tmp;

	return (count++);
}
#include "hotrace.h"

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
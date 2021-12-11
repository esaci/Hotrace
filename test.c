#include <stdlib.h>

int main (void)
{
	char **ptr;

	ptr = malloc(sizeof(*ptr) * 10000000);
	if (!ptr)
		return (1);
	return (0);
}
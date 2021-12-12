#include "hotrace.h"

void	unset_Page(t_Page *tmp)
{
	if (tmp->value)
		free(tmp->value);
	if (tmp->keyword)
		free(tmp->keyword);
	if (tmp->Collision)
		free(tmp->Collision);
	free(tmp);
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
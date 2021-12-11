#include "hotrace.h" 

t_Page	*Page_init(void)
{
	t_Page	*tmp;

	tmp = malloc(sizeof(t_Page) * 2);
	tmp->value = NULL;
	tmp->keyword = NULL;
	tmp->Collision = NULL;
	return (tmp);
}
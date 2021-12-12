#ifndef HOTRACE_H
# define HOTRACE_H


# include "unistd.h"
# include "stdlib.h"
# define DB_TAILLE 10000019

typedef struct s_Page
{
	char *keyword;
	char *value;
	struct s_Page *Collision;
} t_Page;


int	get_next_line(int fd, char **line);
unsigned int	ft_strlen(const char *);
size_t	hashing_function(char *tmp);
size_t	result_function(char *tmp);
void	set_db(t_Page **db);
void	unset_Page(t_Page *tmp);
t_Page	*Page_init(void);

#endif


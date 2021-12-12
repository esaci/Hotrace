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
void	set_db(t_Page **db);
void	unset_page(t_Page *tmp);
t_Page	*page_init(void);
void	unset_db(t_Page **db);
void	fill_db(t_Page **db);
void	result_db(t_Page **db);
char	*ft_recover(char *key, t_Page **db);

#endif


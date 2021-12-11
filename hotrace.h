#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_Page
{
	char *keyword;
	char *value;
	struct s_Page *Collision;
} t_Page;

typedef struct s_db
{
	t_Page	*Page;
	t_Page	*Collision;
	struct s_db *next;
}	t_db;

int				get_next_line(int fd, char **line);
unsigned int	ft_strlen(const char *);
size_t			hashing_function(t_Page *tmp);
size_t			result_function(char *tmp);
int				set_db(t_db **db);
int	set_db_to_count(t_db *db, size_t count, t_Page *tmp);
t_Page			*Page_init(void);
t_db	*get_db_with_count(t_db	*db, size_t	count);

#endif


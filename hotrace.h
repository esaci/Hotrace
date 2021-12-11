#ifndef HOTRACE_H
# define HOTRACE_H

# include "unistd.h"
# include "stdlib.h"

typedef struct s_Page
{
	char *keyword;
	char *value;
	struct s_Page *Collision;
} t_Page;

int	get_next_line(int fd, char **line);
int	ft_strlen(const char *);

#endif


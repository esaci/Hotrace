/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:24:29 by esaci             #+#    #+#             */
/*   Updated: 2021/12/12 14:24:30 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	set_db(t_Page **db)
{
	size_t	i;

	i = 0;
	while (i < DB_TAILLE)
		db[i++] = NULL;
}

void	unset_db(t_Page **db)
{
	size_t	count;

	count = 0;
	while (count < DB_TAILLE)
	{
		if (db[count])
			unset_page(db[count]);
		count++;
	}
	free(db);
}

void	fill_db(t_Page **db)
{
	t_Page			*tmp;
	size_t			count;
	t_Page			*dmp;

	tmp = page_init();
	while (get_next_line(0, &(tmp->keyword)) > 0)
	{
		if (!tmp->keyword || tmp->keyword[0] == '\0')
			break ;
		if (get_next_line(0, &(tmp->value)) <= 0
			|| !tmp->value || tmp->value[0] == '\0')
			break ;
		count = hashing_function(tmp->keyword);
		if (db[count])
		{
			dmp = db[count];
			while (dmp->Collision)
				dmp = dmp->Collision;
			dmp->Collision = tmp;
		}
		else
			db[count] = tmp;
		tmp = page_init();
	}
	unset_page(tmp);
}

void	result_db(t_Page **db)
{
	char	*str;
	char	*tmp;

	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		tmp = ft_recover(str, db);
		if (tmp)
		{
			write(1, tmp, ft_strlen(tmp));
			write(1, "\n", 1);
		}
		else
		{
			write(1, str, ft_strlen(str));
			write(1, ": Not found.\n", 13);
		}
		free(str);
	}
	if (str)
		free(str);
}
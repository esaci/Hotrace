/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athierry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:30:19 by athierry          #+#    #+#             */
/*   Updated: 2021/12/12 01:27:35 by athierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	ft_rec_entry(char *keyword, char *value, t_Page **db)
{
	size_t	hash;
	t_Page	*entry;

	hash = hashing_function(*keyword);
	entry = page_init();
	if (!entry)
		return (1);
	(*entry).keyword = keyword;
	(*entry).value = value;
	if (*(db + hash))
		ft_lstad_back(*(db + hash), entry);
	else
		*(db + hash) = entry;
	return (0);
}

char	*ft_recover(char *key, t_Page **db)
{
	t_Page	*entry;

	entry = *(db + hashing_function(*key));
	if (!entry)
		return ("not found");
	while (!ft_strcmp((*entry).keyword, key))
		entry = (*entry).Collision;
	return ((*entry).value);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if ((*s1 != *s2) || !(*s1) || !(*s2))
			return (((unsigned char) *s1) - ((unsigned char) *s2));
		s1++;
		s2++;
	}
	return (0);
}

void	ft_lstad_back(t_Page *lst, t_Page *new)
{
	while ((*lst).Collision)
		lst = (*lst).Collision;
	(*lst).Collision = new;
}

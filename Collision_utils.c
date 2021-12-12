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

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 || *s2)
	{
		if ((*s1 != *s2) || !(*s1) || !(*s2))
			return (((unsigned char) *s1) - ((unsigned char) *s2));
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_recover(char *key, t_Page **db)
{
	t_Page	*entry;

	entry = db[hashing_function(key)];
	if (!entry)
		return (NULL);
	while (entry->Collision && ft_strcmp(entry->keyword, key))
		entry = (*entry).Collision;
	if (ft_strcmp((*entry).keyword, key))
		return (NULL);
	return ((*entry).value);
}

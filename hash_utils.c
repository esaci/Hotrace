/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:19:42 by esaci             #+#    #+#             */
/*   Updated: 2021/12/12 14:19:43 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t	hashing_function(char *str)
{
	size_t	length;
	size_t	hash;
	size_t	i;

	hash = 5381;
	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		hash = ((hash << 5) + hash) + (*str);
		i++;
		str++;
	}
	hash = hash % DB_TAILLE;
	return (hash);
}

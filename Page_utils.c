/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Page_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:17:04 by esaci             #+#    #+#             */
/*   Updated: 2021/12/12 14:17:08 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	unset_page(t_Page *tmp)
{
	if (tmp->value)
		free(tmp->value);
	if (tmp->keyword)
		free(tmp->keyword);
	if (tmp->collision)
		free(tmp->collision);
	free(tmp);
}

t_Page	*page_init(void)
{
	t_Page	*tmp;

	tmp = malloc(sizeof(t_Page) * 2);
	tmp->value = NULL;
	tmp->keyword = NULL;
	tmp->collision = NULL;
	return (tmp);
}

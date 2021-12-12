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

t_Page	*small_unset_page(t_Page *dmp)
{
	t_Page	*tmp;

	tmp = dmp->collision;
	if (dmp->value)
		free(dmp->value);
	if (dmp->keyword)
		free(dmp->keyword);
	free(dmp);
	return (tmp);
}

void	unset_page(t_Page *tmp)
{
	t_Page	*dmp;

	if (tmp->value)
		free(tmp->value);
	if (tmp->keyword)
		free(tmp->keyword);
	dmp = tmp->collision;
	while (dmp)
		dmp = small_unset_page(dmp);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:23:16 by esaci             #+#    #+#             */
/*   Updated: 2021/12/12 14:23:17 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main( void )
{
	t_Page			**db;

	db = malloc(sizeof(*db) * (DB_TAILLE + 1));
	if (!db)
		return (1);
	set_db(db);
	fill_db(db);
	result_db(db);
	unset_db(db);
	return (0);
}

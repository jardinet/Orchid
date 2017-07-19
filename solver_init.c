/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:33:56 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/15 11:31:42 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	rounded_sqrt(char nb)
{
	char	loop;

	loop = 2;
	while ((loop * loop) < nb)
		loop++;
	return (loop);
}

void		solver(t_tetri **tab, char nb_tetri, char *map_size)
{
	short int	map[16];

	ft_memset((void *)map, 0, 16);
	*map_size = rounded_sqrt(nb_tetri * 4);
	while (solve(tab, (short int *)map, *map_size, 0) == 1)
		(*map_size)++;
}

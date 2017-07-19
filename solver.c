/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:21:39 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/15 12:07:49 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define WIDTH	(tab[(int)tetri])->width
#define HEIGHT	(tab[(int)tetri])->height
#define L1 (short int)(tetri->line_1)
#define L2 (short int)(tetri->line_2)
#define L3 (short int)(tetri->line_3)
#define L4 (short int)(tetri->line_4)

static char	does_it_fit(t_tetri *tetri, short int *map, int x, int y)
{
	if (((map[y] ^ L1 << x) == (map[y] | L1 << x))
	&& (!L2 || ((map[y + 1] ^ L2 << x) == (map[y + 1] | L2 << x)))
	&& (!L3 || ((map[y + 2] ^ L3 << x) == (map[y + 2] | L3 << x)))
	&& (!L4 || ((map[y + 3] ^ L4 << x) == (map[y + 3] | L4 << x))))
	{
		map[y] |= L1 << x;
		L2 != 0 ? (map[y + 1] |= L2 << x) : 0;
		L3 != 0 ? (map[y + 2] |= L3 << x) : 0;
		L4 != 0 ? (map[y + 3] |= L4 << x) : 0;
		tetri->x = x;
		tetri->y = y;
		return (0);
	}
	return (1);
}

void		remove_t(t_tetri *tetri, short int *map, char x, char y)
{
	map[(int)y] ^= L1 << x;
	L2 != 0 ? (map[y + 1] ^= L2 << x) : 0;
	L3 != 0 ? (map[y + 2] ^= L3 << x) : 0;
	L4 != 0 ? (map[y + 3] ^= L4 << x) : 0;
}

char		solve(t_tetri **tab, short int *map, char map_size, char tetri)
{
	char	x;
	char	y;

	if (tab[(int)tetri] == NULL)
		return (0);
	y = 0;
	while (y + HEIGHT < map_size)
	{
		x = 0;
		while (x + WIDTH < map_size)
		{
			if (does_it_fit(tab[(int)tetri], map, (int)x, (int)y) == 0)
			{
				if (solve(tab, map, map_size, tetri + 1) == 0)
					return (0);
				remove_t(tab[(int)tetri], map, x, y);
			}
			x++;
		}
		y++;
	}
	return (1);
}

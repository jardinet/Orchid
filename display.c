/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:08:29 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/14 16:29:48 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define X tetri->x
#define Y tetri->y

static void	monkindagame(UINT line, char **map, t_tetri *tetri, char n)
{
	char		i;
	static char	c = 'A' - 1;

	if (n == 0)
		c++;
	i = 0;
	while (i < 4 - n)
	{
		if (line & (1 << i))
			map[Y + n][X + i] = c;
		i++;
	}
}

static void	back_to_char(t_tetri *tetri, char **map)
{
	monkindagame(tetri->line_1, map, tetri, 0);
	if (tetri->line_2)
		monkindagame(tetri->line_2, map, tetri, 1);
	if (tetri->line_3)
		monkindagame(tetri->line_3, map, tetri, 2);
	if (tetri->line_4)
		monkindagame(tetri->line_4, map, tetri, 3);
}

char		display(t_tetri **tab, char map_size)
{
	char	**map;
	char	i;

	if ((map = (char **)ft_memalloc(sizeof(char*) * map_size)) == NULL)
		return (1);
	i = 0;
	while (i < map_size)
	{
		if ((map[(int)i] = ft_strnew(map_size)) == NULL)
			return (1);
		ft_memset(map[(int)i], '.', map_size);
		i++;
	}
	i = 0;
	while (tab[(int)i])
	{
		back_to_char(tab[(int)i], map);
		i++;
	}
	i = 0;
	while (i < map_size)
		ft_putendl(map[(int)i++]);
	return (0);
}

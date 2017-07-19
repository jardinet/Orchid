/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:30:05 by shuertas          #+#    #+#             */
/*   Updated: 2017/01/15 11:08:18 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	recursive(char *tcpy, char x, char y, char *block)
{
	(*block)++;
	tcpy[y * 5 + x] = 'x';
	if (x > 0 && tcpy[y * 5 + x - 1] == '#')
		recursive(tcpy, x - 1, y, block);
	if (x < 3 && tcpy[y * 5 + x + 1] == '#')
		recursive(tcpy, x + 1, y, block);
	if (y < 3 && tcpy[(y + 1) * 5 + x] == '#')
		recursive(tcpy, x, y + 1, block);
}

static char	second_check(char *tetri)
{
	char	x;
	char	y;
	char	block;

	block = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[y * 5 + x] == '#')
			{
				if (block == 0)
					recursive(tetri, x, y, &block);
				else
					return (1);
			}
			x++;
		}
		y++;
	}
	return (block != 4);
}

static char	first_check(char *tetri, char end)
{
	char	cur;

	cur = 0;
	while (cur < 20)
	{
		if ((cur % 5 < 4 && cur != 20)
		&& (tetri[(int)cur] != '.' && tetri[(int)cur] != '#'))
			return (1);
		else if ((cur % 5 == 4) && tetri[(int)cur] != '\n')
			return (1);
		cur++;
	}
	if (!end && tetri[20] != '\n')
		return (1);
	if (end && tetri[19] != '\n')
		return (1);
	return (0);
}

char		check_tetri(char *tetri, char length)
{
	if (length < 20)
		return (1);
	if (first_check(tetri, length == 20))
		return (1);
	if (second_check(tetri))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:32:48 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/15 11:36:08 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*create_t_elem(void)
{
	t_tetri	*elem;

	if ((elem = (t_tetri*)ft_memalloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	elem->line_1 = 0;
	elem->line_2 = 0;
	elem->line_3 = 0;
	elem->line_4 = 0;
	elem->width = 0;
	elem->height = 0;
	elem->x = 0;
	elem->y = 0;
	return (elem);
}

static void		trim(char *line)
{
	while (line[0] == 0)
	{
		line[0] = line[1];
		line[1] = line[2];
		line[2] = line[3];
		line[3] = 0;
	}
	while (!(line[0] & 1) && !(line[1] & 1) && !(line[2] & 1) && !(line[3] & 1))
	{
		line[0] >>= 1;
		line[1] >>= 1;
		line[2] >>= 1;
		line[3] >>= 1;
	}
}

static void		fill_elem(char *line, t_tetri *elem)
{
	char i;
	char every;

	elem->line_1 = line[0];
	elem->line_2 = line[1];
	elem->line_3 = line[2];
	elem->line_4 = line[3];
	i = 1;
	while (i < 4 && line[(int)i] != 0)
		i++;
	elem->height = i - 1;
	every = line[0] | line[1] | line[2] | line[3];
	i = 1;
	while (i < 4 && every & (1 << i))
		i++;
	elem->width = i - 1;
}

static void		into_binary(char *tetri, t_tetri *elem)
{
	char	x;
	char	y;
	char	line[4];

	y = 0;
	while (y < 4)
	{
		line[(int)y] = 0;
		x = 0;
		while (x < 4)
		{
			if (tetri[y * 5 + x] == 'x')
				line[(int)y] |= 1 << x;
			x++;
		}
		y++;
	}
	trim((char *)line);
	fill_elem((char *)line, elem);
}

t_tetri			*translate(char *tetri)
{
	t_tetri	*elem;

	if ((elem = create_t_elem()) == NULL)
		return (NULL);
	into_binary(tetri, elem);
	return (elem);
}

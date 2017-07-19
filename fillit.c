/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:43:53 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/13 15:36:45 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	ac_errors(int ac)
{
	if (ac == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	return (0);
}

int		main(int ac, char **argv)
{
	t_tetri		**tab;
	char		nb_tetri;
	char		map_size;

	if (ac_errors(ac) == 1)
		return (1);
	if ((tab = initialization(argv[1], &nb_tetri)) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solver(tab, nb_tetri, &map_size);
	if (display(tab, map_size) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

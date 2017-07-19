/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:22:26 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/15 11:35:57 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>

static t_tetri	**trim_tab(t_tetri **tab, char *nb_tetri)
{
	t_tetri	**trimed;
	char	cur;

	cur = 0;
	while (cur < 26 && tab[(int)cur])
		cur++;
	if (!(trimed = ((t_tetri **)ft_memalloc(sizeof(t_tetri *) * (cur + 1)))))
		return (NULL);
	trimed[(int)cur] = NULL;
	*nb_tetri = cur;
	while (cur > 0)
	{
		trimed[cur - 1] = tab[cur - 1];
		cur--;
	}
	return (trimed);
}

static int		check_file(char *file, t_tetri **tab)
{
	int		fd;
	int		ret;
	char	buf[TETRI_SIZE];
	int		count;

	count = 0;
	ret = 1;
	ft_bzero((char *)buf, TETRI_SIZE);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	while (ret > 0 && ret != 20)
	{
		if ((ret = read(fd, buf, TETRI_SIZE)) != -1 || count < 26)
		{
			if (check_tetri(buf, ret) == 1)
				return (1);
			tab[count] = translate(buf);
			count++;
		}
		else
			return (1);
	}
	if (count < 26)
		tab[count] = NULL;
	return (close(fd) == -1);
}

t_tetri			**initialization(char *file, char *nb_tetri)
{
	t_tetri	*tab[26];
	int		i;

	i = 0;
	while (i < 26)
	{
		tab[i] = NULL;
		i++;
	}
	if (check_file(file, tab) == 1)
		return (NULL);
	return (trim_tab(tab, nb_tetri));
}

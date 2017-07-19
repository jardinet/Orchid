/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:28:51 by mwragg            #+#    #+#             */
/*   Updated: 2017/01/17 12:05:38 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define TETRI_SIZE 21
# define UINT unsigned int

typedef struct	s_tetri
{
	UINT		line_1 : 4;
	UINT		line_2 : 3;
	UINT		line_3 : 2;
	UINT		line_4 : 1;
	UINT		width : 2;
	UINT		height : 2;
	UINT		x : 4;
	UINT		y : 4;
}				t_tetri;

t_tetri			**initialization(char *file, char *nb_tetri);
char			check_tetri(char *tetri, char size);
t_tetri			*translate(char *tetri);
void			solver(t_tetri **tab, char nb_tetri, char *map_size);
char			solve(t_tetri **tab, short int *map,
				char map_size, char tetri);
char			display(t_tetri **tab, char map_size);

#endif

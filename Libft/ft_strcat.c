/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:12:20 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:37:01 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	cur;
	size_t	cur_2;

	cur = 0;
	cur_2 = 0;
	while (s1[cur])
		cur++;
	while (s2[cur_2])
	{
		s1[cur] = s2[cur_2];
		cur_2++;
		cur++;
	}
	s1[cur] = '\0';
	return (s1);
}

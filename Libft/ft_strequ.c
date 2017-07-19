/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:04 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:39:08 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	cur;

	cur = 0;
	while (s1[cur] && s2[cur] && s1[cur] == s2[cur])
		cur++;
	if (s1[cur] == '\0' && s2[cur] == '\0')
		return (1);
	return (0);
}

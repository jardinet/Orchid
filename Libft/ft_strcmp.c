/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:59:02 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:37:55 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	cur;

	cur = 0;
	while (s1[cur] && s2[cur] && s1[cur] == s2[cur])
		cur++;
	return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
}

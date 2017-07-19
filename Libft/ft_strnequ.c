/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:11:04 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:41:26 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	cur;

	cur = 0;
	while (s1[cur] && s2[cur] && s1[cur] == s2[cur] && cur < n)
		cur++;
	if ((s1[cur] == '\0' && s2[cur] == '\0') || cur == n)
		return (1);
	return (0);
}

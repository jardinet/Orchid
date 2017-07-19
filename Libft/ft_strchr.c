/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:40:09 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:37:15 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cur;

	cur = 0;
	while (s[cur] != c && s[cur])
		cur++;
	if (s[cur] || c == '\0')
		return ((char *)&(s[cur]));
	return (NULL);
}

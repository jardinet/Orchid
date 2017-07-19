/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:42:52 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 17:07:44 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cur;

	cur = 0;
	while (src[cur] && cur < len)
	{
		dst[cur] = src[cur];
		cur++;
	}
	if (cur < len)
	{
		while (cur < len)
		{
			dst[cur] = '\0';
			cur++;
		}
	}
	return (dst);
}

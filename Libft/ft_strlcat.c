/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:12:20 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:40:00 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cur;
	size_t	cur_2;
	int		size_src;
	int		size_dst;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	cur = 0;
	cur_2 = 0;
	while (dst[cur])
		cur++;
	if (size < cur)
		return (size_src + size);
	while (cur < size - 1 && src[cur_2])
	{
		dst[cur] = src[cur_2];
		cur_2++;
		cur++;
	}
	dst[cur] = '\0';
	return (size_src + size_dst);
}

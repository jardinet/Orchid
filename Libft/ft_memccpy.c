/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:39:39 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 16:09:22 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			cur;
	unsigned char	*ptr;
	unsigned char	*ptr_2;

	cur = 0;
	ptr = (unsigned char *)dst;
	ptr_2 = (unsigned char *)src;
	while (cur < n)
	{
		if (ptr_2[cur] == (unsigned char)c)
		{
			ptr[cur] = ptr_2[cur];
			return (dst + cur + 1);
		}
		else
			ptr[cur] = ptr_2[cur];
		cur++;
	}
	return (NULL);
}

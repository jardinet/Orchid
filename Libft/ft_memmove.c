/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:50:04 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 16:26:26 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			cur;
	unsigned char	*ptr;
	unsigned char	*ptr_2;

	cur = len;
	ptr = (unsigned char *)dst;
	ptr_2 = (unsigned char *)src;
	if (dst > src)
	{
		while (cur > 0)
		{
			ptr[cur - 1] = ptr_2[cur - 1];
			cur--;
		}
	}
	else
		src = ft_memcpy(dst, src, len);
	return (dst);
}

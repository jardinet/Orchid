/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:39:39 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:34:09 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			cur;
	unsigned char	*ptr;
	unsigned char	*ptr_2;

	cur = 0;
	ptr = (unsigned char *)dst;
	ptr_2 = (unsigned char *)src;
	while (cur < n)
	{
		ptr[cur] = ptr_2[cur];
		cur++;
	}
	return (dst);
}

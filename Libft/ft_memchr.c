/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:28:29 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 16:35:47 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			cur;

	cur = 0;
	ptr = (unsigned char *)s;
	while (cur < n)
	{
		if (ptr[cur] == (unsigned char)c)
			return (ptr + cur);
		cur++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:45:20 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 16:42:17 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr_2;
	size_t			cur;

	cur = 0;
	ptr = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	while (cur < n && ptr[cur] == ptr_2[cur])
		cur++;
	if (cur != n)
		return ((unsigned char)ptr[cur] - (unsigned char)ptr_2[cur]);
	return (0);
}

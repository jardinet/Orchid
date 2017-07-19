/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:58:37 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:35:00 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cur;
	unsigned char	*ptr;

	cur = 0;
	ptr = b;
	while (cur < len)
		ptr[cur++] = (unsigned char)c;
	return (b);
}

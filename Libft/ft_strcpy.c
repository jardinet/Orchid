/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:42:52 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:38:15 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	cur;

	cur = 0;
	while (src[cur] != '\0')
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = '\0';
	return (dst);
}

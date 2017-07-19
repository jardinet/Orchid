/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:42:27 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/22 10:44:22 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	cur;

	str = NULL;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	ft_memset(str, '\0', size + 1);
	return (str);
}

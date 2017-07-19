/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:10:04 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:42:43 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	cur;

	str = NULL;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	cur = 0;
	while (s[cur] && cur < len)
	{
		str[cur] = s[(size_t)start + cur];
		cur++;
	}
	return (str);
}

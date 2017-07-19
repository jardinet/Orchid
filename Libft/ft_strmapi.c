/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:52:21 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/23 10:44:32 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	cur;
	size_t	size;
	char	*new_str;

	size = ft_strlen(s);
	new_str = ft_strnew(size);
	if (new_str == NULL)
		return (NULL);
	cur = 0;
	while (cur < size)
	{
		new_str[cur] = (*f)(cur, s[cur]);
		cur++;
	}
	return (new_str);
}

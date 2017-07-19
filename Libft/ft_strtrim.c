/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:41:00 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:42:56 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	cur;

	len = ft_strlen(s);
	cur = 0;
	while (s[cur]
	&& (s[cur] == ' '
	|| s[cur] == '\n'
	|| s[cur] == '\t'))
		cur++;
	start = cur;
	if (start == len)
		return (ft_strnew(0));
	cur = len;
	while (cur > 0
	&& (s[cur - 1] == ' '
	|| s[cur - 1] == '\n'
	|| s[cur - 1] == '\t'))
		cur--;
	end = cur;
	str = ft_strsub(s, (unsigned int)start, end - start);
	return (str);
}

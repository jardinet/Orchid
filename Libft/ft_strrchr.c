/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:40:09 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:42:06 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cur;

	cur = ft_strlen(s);
	while (s[cur] != c && cur >= 0)
		cur--;
	if (cur >= 0 || c == '\0')
		return ((char *)&(s[cur]));
	return (NULL);
}

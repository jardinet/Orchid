/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:26:23 by shuertas          #+#    #+#             */
/*   Updated: 2017/01/17 12:04:21 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	total_len;
	char	*str;
	char	*str_2;

	len_1 = (s1) ? ft_strlen(s1) : 0;
	len_2 = (s2) ? ft_strlen(s2) : 0;
	total_len = len_1 + len_2;
	str = NULL;
	str = ft_strnew(total_len);
	if (str == NULL)
		return (NULL);
	if (len_1 != 0)
		str = ft_strcpy(str, s1);
	str_2 = str + len_1;
	if (len_2 != 0)
		str_2 = ft_strcpy((str + len_1), s2);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:01:16 by shuertas          #+#    #+#             */
/*   Updated: 2017/01/02 18:23:14 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			cur;
	unsigned long	value;
	char			minus;

	cur = 0;
	value = 0;
	minus = 1;
	while (str[cur] == ' ' || str[cur] == '\n' || str[cur] == '\f'
	|| str[cur] == '\t' || str[cur] == '\r' || str[cur] == '\v')
		cur++;
	if (str[cur] == '-')
	{
		minus = -1;
		cur++;
	}
	else if (str[cur] == '+')
		cur++;
	while (str[cur] && str[cur] >= '0' && str[cur] <= '9')
	{
		value *= 10;
		value += str[cur] - '0';
		cur++;
	}
	value *= minus;
	return (value);
}

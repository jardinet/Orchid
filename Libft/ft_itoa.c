/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:11:40 by shuertas          #+#    #+#             */
/*   Updated: 2016/12/15 12:21:38 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_getsize(long long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(long long n)
{
	size_t				size;
	unsigned long long	nbr;
	size_t				minus;
	char				*str;

	nbr = n;
	size = itoa_getsize(n);
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		nbr *= -n;
	}
	str = (char *)ft_strnew(size + minus);
	if (str == NULL)
		return (NULL);
	while (size > 0)
	{
		str[size - 1 + minus] = nbr % 10 + '0';
		nbr /= 10;
		size--;
	}
	if (minus)
		str[0] = '-';
	return (str);
}

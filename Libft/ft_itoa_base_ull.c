/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:05:42 by shuertas          #+#    #+#             */
/*   Updated: 2016/12/15 12:40:15 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	itoa_base_getsize(unsigned long long n, int base)
{
	size_t		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n /= base;
	}
	return (size);
}

static char		*itoa_base(unsigned long long n, int base, char *val)
{
	size_t				size;
	char				*str;

	size = itoa_base_getsize(n, base);
	str = (char *)ft_strnew(size);
	if (!str)
		return (NULL);
	while (size > 0)
	{
		str[size - 1] = val[n % base];
		n /= base;
		size--;
	}
	return (str);
}

static char		*itoa_unary(unsigned long long n, char *val)
{
	char				*str;

	str = (char *)ft_strnew(n);
	if (!str)
		return (NULL);
	ft_memset(str, *val, n);
	return (str);
}

char			*ft_itoa_base_ull(unsigned long long n, int base, char *val)
{
	if (base > 1)
		return (itoa_base(n, base, val));
	if (base == 1)
		return (itoa_unary(n, val));
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:05:42 by shuertas          #+#    #+#             */
/*   Updated: 2016/12/19 16:45:37 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	itoa_base_getsize(long long n, int base)
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

static char		*itoa_base(long long n, int base, char *val)
{
	size_t				size;
	unsigned long long	nbr;
	size_t				minus;
	char				*str;

	nbr = n;
	size = itoa_base_getsize(n, base);
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		nbr = -n;
	}
	str = (char *)ft_strnew(size + minus);
	if (!str)
		return (NULL);
	while (size > 0)
	{
		str[size - 1 + minus] = val[nbr % base];
		nbr /= base;
		size--;
	}
	if (minus)
		str[0] = '-';
	return (str);
}

static char		*itoa_unary(long long n, char *val)
{
	unsigned long long	nbr;
	char				*str;
	size_t				minus;

	if (n < 0)
	{
		minus = 1;
		nbr = -n;
	}
	else
	{
		minus = 0;
		nbr = n;
	}
	str = (char *)ft_strnew(nbr + minus);
	if (!str)
		return (NULL);
	ft_memset((str + minus), *val, nbr);
	if (minus)
		str[0] = '-';
	return (str);
}

char			*ft_itoa_base(long long n, int base, char *val)
{
	if (base > 1)
		return (itoa_base(n, base, val));
	if (base == 1)
		return (itoa_unary(n, val));
	return (NULL);
}

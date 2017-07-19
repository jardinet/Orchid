/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:27:48 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/22 11:00:31 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	size_t	nbr;
	size_t	pow;

	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -(size_t)n;
	}
	else
		nbr = (size_t)n;
	pow = 1;
	while (n != 0)
	{
		pow *= 10;
		n /= 10;
	}
	pow /= 10;
	while (pow > 0)
	{
		ft_putchar((nbr / pow) + '0');
		nbr %= pow;
		pow /= 10;
	}
}

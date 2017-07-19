/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:27:48 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/22 11:25:42 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	nbr;
	size_t	pow;

	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd((nbr / pow) + '0', fd);
		nbr %= pow;
		pow /= 10;
	}
}

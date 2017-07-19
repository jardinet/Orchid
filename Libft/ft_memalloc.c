/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:23:45 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/22 11:45:28 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*cur;

	cur = NULL;
	cur = (void *)malloc(size);
	if (cur == NULL)
		return (NULL);
	ft_bzero(cur, size);
	return (cur);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:13:37 by shuertas          #+#    #+#             */
/*   Updated: 2016/12/16 17:57:13 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (!(alst && *alst && del))
		return ;
	while (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = next;
	}
}

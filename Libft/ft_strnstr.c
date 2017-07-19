/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:10:08 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:41:49 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cur;
	size_t	cur_2;

	if (!little[0])
		return ((char *)&(big[0]));
	cur = 0;
	while (big[cur] && cur < len)
	{
		while (big[cur] && big[cur] != little[0] && cur < len)
			cur++;
		cur_2 = 0;
		while (big[cur + cur_2] && little[cur_2]
		&& big[cur + cur_2] == little[cur_2] && cur < len && cur + cur_2 < len)
			cur_2++;
		if (little[cur_2] == '\0' && cur < len)
			return ((char *)&(big[cur]));
		else
		{
			if (big[cur] && cur < len)
				cur++;
			else
				return (NULL);
		}
	}
	return (NULL);
}

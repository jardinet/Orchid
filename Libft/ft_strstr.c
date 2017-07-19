/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:10:08 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/21 15:42:32 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	cur;
	int	cur_2;

	if (!little[0])
		return ((char *)&(big[0]));
	cur = 0;
	while (big[cur])
	{
		while (big[cur] && big[cur] != little[0])
			cur++;
		cur_2 = 0;
		while (big[cur + cur_2] && little[cur_2]
		&& big[cur + cur_2] == little[cur_2])
			cur_2++;
		if (little[cur_2] == '\0')
			return ((char *)&(big[cur]));
		else
		{
			if (big[cur])
				cur++;
			else
				return (NULL);
		}
	}
	return (NULL);
}

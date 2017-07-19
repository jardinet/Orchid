/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:13:28 by shuertas          #+#    #+#             */
/*   Updated: 2016/11/22 10:50:48 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strsplit_indexc(char const *s, char c)
{
	size_t	cur;

	cur = 0;
	if (s[cur] == '\0')
		return (-1);
	while (s[cur] && s[cur] != c)
		cur++;
	return (cur);
}

static size_t	strsplit_getnbrwords(char const *s, char c)
{
	size_t	nbr;
	size_t	cur;
	int		tmp;

	nbr = 0;
	cur = 0;
	tmp = 0;
	while (tmp != -1)
	{
		tmp = strsplit_indexc(s + cur, c);
		if (tmp != -1)
			nbr++;
		cur += (size_t)tmp;
		while ((s + cur)[0] == c)
			cur++;
	}
	return (nbr);
}

static char		*strsplit_getword(char **s, char c)
{
	char	*str;
	int		len;

	len = strsplit_indexc(*s, c);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, *s, len);
	(*s) += len;
	while ((*s)[0] == c)
		(*s)++;
	return (str);
}

static void		strsplit_errfree(char ***tab, size_t nbr)
{
	size_t	cur;

	cur = 0;
	while (cur < nbr)
	{
		free((*tab)[cur]);
		cur++;
	}
	free(*tab);
	(*tab) = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	nbr;
	size_t	cur;
	char	*ptr_s;
	char	**tab;

	cur = 0;
	nbr = 0;
	ptr_s = (char *)s;
	while (*ptr_s == c)
		ptr_s++;
	nbr = strsplit_getnbrwords(ptr_s, c);
	tab = (char **)malloc(sizeof(char **) * (nbr + 1));
	if (tab == NULL)
		return (NULL);
	tab[nbr] = NULL;
	while (cur < nbr && tab != NULL)
	{
		tab[cur] = strsplit_getword(&ptr_s, c);
		if (tab[cur] == NULL)
			strsplit_errfree(&tab, cur);
		cur++;
	}
	return (tab);
}

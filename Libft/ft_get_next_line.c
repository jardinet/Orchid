/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuertas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:38:46 by shuertas          #+#    #+#             */
/*   Updated: 2016/12/11 13:29:35 by shuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF	tmp[0]
#define STR1	tmp[1]
#define STR2	tmp[2]

static void		add_fd(t_list **tab_fd, int fd)
{
	t_fd	*file;
	t_list	*new;

	file = ft_memalloc(sizeof(t_fd));
	file->fd = fd;
	file->keep = NULL;
	file->end = 0;
	if (*tab_fd == NULL)
		*tab_fd = ft_lstnew(file, sizeof(t_fd));
	else
	{
		new = *tab_fd;
		new = ft_lstnew(file, sizeof(t_fd));
		new->next = *tab_fd;
		*tab_fd = new;
	}
}

static	char	search_fd(t_list *tab_fd, int fd)
{
	t_fd	*file;

	if (tab_fd != NULL)
	{
		while (tab_fd)
		{
			file = (t_fd *)(tab_fd->content);
			if (file->fd == fd)
				return (1);
			tab_fd = tab_fd->next;
		}
	}
	return (0);
}

static char		get_keep(t_fd *file, char **str)
{
	char	*tmp;
	char	*tmp2;

	if (!file->keep)
		return (1);
	if (ft_strchr(file->keep, '\n'))
		tmp = ft_strsub(file->keep, 0,
		ft_strchr(file->keep, '\n') - file->keep);
	else
		tmp = ft_strsub(file->keep, 0, ft_strlen(file->keep));
	tmp2 = ft_strjoin(*str, tmp);
	ft_strdel(str);
	*str = tmp2;
	if (ft_strchr(file->keep, '\n'))
	{
		free(tmp);
		tmp = ft_strsub(ft_strchr(file->keep, '\n'), 1,
		ft_strlen(ft_strchr(file->keep, '\n')) - 1);
		ft_strdel(&(file->keep));
		file->keep = tmp;
		return (0);
	}
	ft_strdel(&tmp);
	ft_strdel(&(file->keep));
	return (1);
}

static char		read_fd(t_fd *file, char **str)
{
	char	*tmp[3];

	BUFF = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (read(file->fd, BUFF, BUFF_SIZE) < 0)
			return (0);
		if (ft_strchr(BUFF, '\0') < (BUFF + BUFF_SIZE))
			file->end = 1;
		if (ft_strchr(BUFF, '\n'))
			STR1 = ft_strsub(BUFF, 0, ft_strchr(BUFF, '\n') - BUFF);
		else
			STR1 = ft_strsub(BUFF, 0, ft_strlen(BUFF));
		STR2 = ft_strjoin(*str, STR1);
		ft_strdel(str);
		*str = STR2;
		if (file->end || ft_strchr(BUFF, '\n'))
			break ;
	}
	if (ft_strchr(BUFF, '\n'))
		file->keep = ft_strsub(ft_strchr(BUFF, '\n'), 1,
		ft_strlen(ft_strchr(BUFF, '\n')) - 1);
	ft_strdel(&(STR1));
	ft_strdel(&(BUFF));
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list		*tab_fd = NULL;
	t_list				*ptr_list;
	t_fd				*ptr_fd;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!search_fd(tab_fd, fd))
		add_fd(&tab_fd, fd);
	ptr_list = tab_fd;
	while (1)
	{
		ptr_fd = (t_fd *)(ptr_list->content);
		if (ptr_fd->fd == fd)
			break ;
		ptr_list = ptr_list->next;
	}
	*line = NULL;
	if (ptr_fd->end && !ptr_fd->keep)
		return (0);
	if (get_keep(ptr_fd, line))
		if (!read_fd(ptr_fd, line))
			return (-1);
	if (*line)
		return (((*line)[0] == '\0' && !ptr_fd->keep) ? 0 : 1);
	return (0);
}

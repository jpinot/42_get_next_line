/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:52:53 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/03 20:59:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_checkfile(const int fd, t_list **file)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static int	ft_copy_line(char *c, char **l)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while(c[++i])
	{
		if (c[i] == '\n')
			break ;
	}
	*l = ft_strnew(i + 1);
	*l = ft_strncpy(*l, c, i);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list		*mem;
	char		tmp[BUFF_SIZE + 1];
	int		i;

	if ((fd < 0 || line == NULL || read(fd, tmp, 0) < 0))
		return (-1);
	mem = ft_checkfile(fd, &file);
	while ((i = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[i] = 0;
		mem->content = ft_strjoin(mem->content, tmp);
//			mem->content = ft_strdup(tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (i < BUFF_SIZE && !ft_strlen(mem->content))
                return (0);
	i = ft_copy_line(mem->content, line);
	if (i < (int)ft_strlen(mem->content))
		mem->content += (i + 1);
	else
		ft_strclr(mem->content);
	return (1);
}

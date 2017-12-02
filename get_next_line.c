/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:52:53 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/02 23:09:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_checkfile(const int fd, t_list mem)
{
	if (mem.content_size != (size_t)fd)
	{
		mem.content_size = fd;
		mem.content = NULL;
	}
}

static int	ft_copy_line(char *c, char **l)
{
	char	*tmp;
	int		i;
	int		j;
	int		g;

	i = 0;
	j = 0;
	g = 0;
	while (c[j] != '\n' && c[g])
		j++;
	tmp = ft_strnew(j);
	while (c[g] != '\n' && c[g])
	{
		tmp[i] = c[g];
		i++;
		g++;
	}
	if (c[g] == '\n')
		tmp[i] = c[g];
	if (!(*l = ft_strjoin(*l, tmp)))
		*l = ft_strdup(tmp);
	return (g);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	mem;
	char			tmp[BUFF_SIZE + 1];
	int				i;
	int				j;

	j = 0;
	*line = NULL;
	ft_memset(tmp,'\0',BUFF_SIZE + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	ft_checkfile(fd, mem);
	if (mem.content)
		mem.content += 1;
	while ((i = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[i] = 0;
		if (!(mem.content = ft_strjoin(mem.content, tmp)))
			mem.content = ft_strdup(tmp);
		if (ft_strchr(mem.content, '\n'))
			break ;
	}
	j = ft_copy_line(mem.content, line);
	mem.content += j;
	if (i < BUFF_SIZE && ft_strlen(mem.content) <= 0)
	{
		ft_putchar('8');
		return (0);
	}
	ft_putchar('3');
	return (1);
}

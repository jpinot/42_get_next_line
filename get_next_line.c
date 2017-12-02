/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:52:53 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/01 20:00:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define B_SIZE 1

static void	ft_checkfile(const int fd, t_list mem, int j)
{
	if (mem.content_size != (size_t)fd)
	{
		mem.content_size = fd;
		mem.content = NULL;
		j = fd - 3;
	}
}

static int	ft_copy_line(char *c, char *l)
{
	char	*tmp;
	int	i;
	int	j;
	int	g;

	i = 0;
	j = 0;
	g = 0;
	while (c[j] != '\n')
		j++;
	tmp = ft_strnew(j);
	while (c[g] != '\n' )
	{
		tmp[i] = c[g];
		i++;
		g++;
	}
	if (c[g] == '\n')
		tmp[i] = c[g];
	if (l == NULL)
		l = ft_strdup(tmp);
	else
		l = ft_strjoin(l, tmp);
	return (g);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	mem;
	char			tmp[B_SIZE + 1];
	int				i;
	int				j;

	j = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	ft_checkfile(fd, mem, j);
	if (mem.content)
		mem.content+= 1;
	while ((i = read(fd, tmp, B_SIZE)))
	{
		tmp[i] = 0;
		if (mem.content == NULL)
                	mem.content = ft_strdup(tmp);
		else
			mem.content = ft_strjoin(mem.content, tmp);
		if (ft_strchr(mem.content, '\n'))
		{
			break ;
		}
	}
	i = ft_copy_line(mem.content, line[j]);
	mem.content += i;
	ft_putstr(line[j]);
	if (!ft_strlen(mem.content))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:52:53 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/30 20:26:53 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_checkfile(fd, mem, int j)
{
	if (mem->contnent_size != fd)
	{
		mem->content_size = fd;
		mem->content = NULL;
		j = fd - 3;
	}
}

static void	ft_copy_line(char *c, char *l, char *tmp)
{
	char	*tmp2;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp2 = ft_strnew(ft_strlen(c - tmp));
	while (tmp2[i] != '\n' )
	{
		tmp2[i] = c[j];
		i++;
		j++;
	}
	c = tmp;
	l = ft_strjoin(l, tmp2)
}

int		get_next_line(const int fd, char **line)
{
	static t_list	mem;
	char		tmp[B_SIZE + 1];
	int		i;
	int		j;

	j = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	ft_checkfile(fd, mem, j);
	if (mem->content)
		mem->content+= 1;
	while (i = read(fd, tmp, B_SIZE))
	{
		tmp[i] = 0;
		mem->content = ft_strjoin(mem->content, tmp);
		if (tmp = ft_strchr(mem->content, '\n')
			break ;
	}
	ft_copy_line(mem->content, line[j], tmp);
	if (i < B_SIZE)
		return (0);
	return (1);
}

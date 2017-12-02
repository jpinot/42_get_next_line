/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:49:43 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/02 23:03:35 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include "get_next_line.h"

int     get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else 
		fd = open(argv[1], O_RDONLY);
	fd = 1;
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
//		free(line);
	}
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	get_next_line(fd, &line);
//	ft_putstr(line);
	if (argc == 2)
		close(fd);
	return (0);
}

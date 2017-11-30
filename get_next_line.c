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

int		ft_check(const int fd, char *buff, int *tmp, int i)
{
	int j;

	while (ft_strstr(buff, tmp) != NULL && )
	{
		j = read(fd, buff, nbytes);
	}
	buff[j] = 0;
	j = 0;
	while(buff[i])

int		get_next_line(const int fd, char **line)
{
	static int	*tmp = NULL;
	char		buff;
	int			i;
	int			space_cnt;

	i = 1;
	if (tmp == NULL)
	{
		tmp = (char *)malloc(sizeof(int));
		tmp = NULL;
	}
	while(i > 0)
	{
		if (space_cnt = ft_check(fd, buff, tmp, i)

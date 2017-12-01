
#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

static void	print_line(int fd, char *c)
{
	read(fd, c, 2);
}

int		main(int argc, char **argv)
{
	int	fd;
	char	c[66];
	int	i;

	i = 0;
	if (argc == 1)
		fd = 0;
	fd = open(argv[1], O_RDONLY);
	while (i++ < 4)
	{
		print_line(fd, c);
		printf("%s \n", c);
	}
//	while ((i = read(fd, c, 2)))
//	{
//		printf("%s \n", c);
//        	printf("%i \n", i);
//	}
//	while (get_next_line(fd, &line) == 1)
//	{
//		ft_putendl(line);
//		free(line);
//	}
//	if (argc == 2)
//		close(fd);
	return (0);
}


#include <stdio.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *d1;
	unsigned char *d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (*d1 || *d2)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		d1++;
		d2++;
	}
	return (0);
}

int		main(void)
{
	char a[] = "abcd";
	char b[] = "abcde";
	printf("%i", ft_strcmp(a, b));
	return (0);
}

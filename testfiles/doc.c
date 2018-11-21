#include <unistd.h>
#include <stdlib.h>

void	putchart(char c, int i)
{
	while (i--)
		write(1, &c, 1);
}

void	printstrt(char *s, int p)
{
	int i = 0;
	int b = 0;
	while (b < p)
	{
		while (s[i] != 0)
		{
			putchart(s[i], b);
			i++;
		}
		i = 0;
		b++;
	}
}

int		main(int ac, char **av)
{
	int a;
	if (ac == 2)
	{
		a = atoi(av[1]);
		printstrt("abcdefghijklmnopqrstuvwxyz", a);
	}
	return (0);
}

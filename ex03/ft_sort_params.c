#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_args(int argc, char **argv)
{
	int		i;
	char	*s1;
	char	*s2;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		s1 = argv[i];
		s2 = argv[i + 1];
		if (s2 == 0)
			return ;
		if (ft_strcmp(s1, s2) > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (0);
	ft_sort_args(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
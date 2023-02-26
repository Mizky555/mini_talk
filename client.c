#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(char *str)//char to int
{
	int	i;
	int	num;
	int	a;

	i = 0;
	num = 0;
	a = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)//32->space
		i++;
	if (str[i] == '-')
		a = a * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * a);
}

void	send_char(char c, int p_id)
{
	unsigned int	binary;
	int i;

	i = 0;
	binary = c;
	while (i <= 7)
	{
		if ((binary >> i) & 1)
			kill(p_id, SIGUSR1);
		else
			kill(p_id, SIGUSR2);
		usleep(200);
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit (1);
	while (argv[2][i])
	{
		send_char(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	return (0);
}


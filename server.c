#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_sig_handler(int sig)
{
	static int	cha_one;
	static int	cha_two;

	cha_nom = 0;
	if (sig == SIGUSR1)
	{

	}
	else if (sig == SIGUSR2)
	{
		printf("0\n");
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i = i + 1;
	}
}

void	ft_putnbr(int i)
{
	int	num;

	if (i < 0)
	{
		write (1, "-", 1);
		i = i * -1;
	}
	if (i >= 10)
		ft_putnbr(i/10);
	num = (i % 10) + '0';
	write (1, &num, 1);
}

int	main(void)
{
	int	p_id;

	p_id = getpid();
	ft_putstr("PID : ");
	ft_putnbr(p_id);
	while (1)
	{
		signal(SIGUSR1, ft_sig_handler);
		signal(SIGUSR2, ft_sig_handler);
	}
	return (0);
}

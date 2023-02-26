/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:55:24 by tsirirak          #+#    #+#             */
/*   Updated: 2023/02/26 20:56:04 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_putchar(char i)
{
	write(1, &i, 1);
}

void	ft_sig_handler(int sig)
{
	static int	ch = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		ch = ch + 1;
	i = i + 1;
	if (i == 8)
	{
		ft_putchar(ch);
		i = 0;
		ch = 0;
	}
	else
		ch <<= 1;
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
		ft_putnbr(i / 10);
	num = (i % 10) + '0';
	write (1, &num, 1);
}

int	main(void)
{
	int	p_id;

	p_id = getpid();
	ft_putstr("PID : ");
	ft_putnbr(p_id);
	ft_putstr("\n");
	while (1)
	{
		signal(SIGUSR1, ft_sig_handler);
		signal(SIGUSR2, ft_sig_handler);
	}
	return (0);
}

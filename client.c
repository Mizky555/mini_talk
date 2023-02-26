/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:56:34 by tsirirak          #+#    #+#             */
/*   Updated: 2023/02/26 21:17:19 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	a;

	i = 0;
	num = 0;
	a = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
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
	int				i;

	i = 7;
	binary = c;
	while (i >= 0)
	{
		if ((binary >> i) & 1)
		{
			if (kill(p_id, SIGUSR1) == -1)
				exit (1);
		}
		else
		{
			if (kill(p_id, SIGUSR2) == -1)
				exit (1);
		}
		usleep(125);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	p_id;

	i = 0;
	p_id = ft_atoi(argv[1]);
	if (argc != 3)
		exit (1);
	if (p_id <= 0)
		exit (1);
	while (argv[2][i])
	{
		send_char(argv[2][i], p_id);
		i++;
	}
	return (0);
}

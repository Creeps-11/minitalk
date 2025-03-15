/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:10:44 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/03/15 17:13:06 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pos_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			nbr = (nbr * 10) + (str[i] - 48);
		else
			return (0);
		i++;
	}
	return (nbr);
}

void	puterr(char *s)
{
	ft_putstr_fd(s, 2);
}

void	try_kill(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		puterr("Failure when trying to send signal\n");
		puterr("Check PID or if target server is running\n");
		exit(EXIT_FAILURE);
	}
}

void	killstring(int pid, char *s)
{
	int		i;
	char	c;

	while (*s)
	{
		i = 8;
		c = *s++;
		while (i--)
		{
			if (c >> i & 1)
				try_kill(pid, SIGUSR2);
			else
				try_kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		try_kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (pos_atoi(argv[1]) > 0)
			killstring(ft_atoi(argv[1]), argv[2]);
		else
			puterr("Wrong PID\n");
		return (0);
	}
	puterr("Wrong number of arguments\n");
	return (0);
}

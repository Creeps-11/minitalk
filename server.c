/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:10:41 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/03/18 16:49:25 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_err = 0;

void	puterr(char *s)
{
	ft_putstr_fd(s, 2);
}

char	*join_n_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

char	*display_string(char *s)
{
	ft_printf("%s\n", s);
	free(s);
	return ("");
}

static void	action(int sig)
{
	static int	i = 0;
	static char	c = 0;
	static char	*string = "";

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (ft_strlen(string) == 0)
			string = ft_strdup(&c);
		else
			string = join_n_free(string, &c);
		if (!string)
		{
			g_err = 1;
			return (puterr("Malloc error\n"));
		}
		if (!c)
			string = display_string(string);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &action;
	if (sigaction(SIGUSR1, &act, 0) == -1
		|| sigaction(SIGUSR2, &act, 0) == -1)
		return (puterr("Error when setting sigaction\n"), 1);
	ft_printf("Server PID is : %d\n", getpid());
	while (1)
	{
		pause();
		if (g_err == 1)
			return (1);
	}
	return (0);
}

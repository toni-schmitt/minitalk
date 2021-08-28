/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:00:06 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/28 21:06:01 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message	g_msg;

void	high_bit(int pid)
{
	(void)pid;
	g_msg.c = g_msg.c | g_msg.mask;
	g_msg.mask /= 2;
}

void	low_bit(int pid)
{
	(void)pid;
	g_msg.mask /= 2;
}

void	char_recieved(int pid)
{
	(void)pid;
	ft_printf("%c", g_msg.c);
	g_msg.c = 0;
	g_msg.mask = 128;
}

void	complete(int pid)
{
	(void)pid;
	ft_printf("\n");
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	g_msg.c = 0;
	g_msg.mask = 128;
	while (1)
	{
		signal(SIGUSR1, high_bit);
		signal(SIGUSR2, low_bit);
		signal(SIGTERM, complete);
		signal(SIGINFO, char_recieved);
	}
	return (EXIT_SUCCESS);
}

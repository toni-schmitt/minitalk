/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:00:06 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/29 15:05:09 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message	g_msg;

void	high_bit(int sig)
{
	(void)sig;
	g_msg.c = g_msg.c | g_msg.mask;
	g_msg.mask /= 2;
	g_msg.byte_count++;
}

void	low_bit(int sig)
{
	(void)sig;
	g_msg.mask /= 2;
	g_msg.byte_count++;
}

void	char_recieved(void)
{
	ft_printf("%c", g_msg.c);
	g_msg.c = 0;
	g_msg.mask = 128;
	g_msg.byte_count = 0;
}

void	complete(void)
{
	ft_printf("\n");
	g_msg.c = 0;
	g_msg.mask = 128;
	g_msg.byte_count = 0;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	g_msg.c = 0;
	g_msg.mask = 128;
	g_msg.byte_count = 0;
	while (1)
	{
		signal(SIGUSR1, high_bit);
		signal(SIGUSR2, low_bit);
		if (g_msg.c == SIG_STOP)
			complete();
		if (g_msg.byte_count == 8)
			char_recieved();
	}
	return (EXIT_SUCCESS);
}

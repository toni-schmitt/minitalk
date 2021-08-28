/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:00:04 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/28 21:08:21 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_char(unsigned char c, int pid)
{
	int	mask;
	int	i;

	i = 0;
	mask = 128;
	while (i < 8)
	{
		if ((c & mask) > 0)
			kill(pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		mask /= 2;
		i++;
		usleep(100);
	}
}

void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_char(*message, pid);
		kill(pid, SIGINFO);
		usleep(50);
		message++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
		return (ft_puterror("Usage: ./client [PID] [MESSAGE]"));
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(server_pid, message);
	usleep(50);
	kill(server_pid, SIGTERM);
	return (EXIT_SUCCESS);
}

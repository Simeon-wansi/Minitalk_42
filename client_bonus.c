/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:11:53 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/11 17:22:57 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, ".", 1);
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error,  DO: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, ack_handler);
	i = 0;
	while (i < (int)ft_strlen(message))
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:12:02 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/12 13:33:10 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	current_char = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_char = current_char << 1;
	if (signum == SIGUSR2)
		current_char = current_char | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

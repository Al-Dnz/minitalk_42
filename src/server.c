/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:59:15 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/22 12:35:02 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		g_state.c |= g_state.head_bit;
	g_state.head_bit >>= 1;
	if (!g_state.head_bit)
	{
		g_state.releasable_char = true;
		if (g_state.c == 0)
			kill(info->si_pid, SIGUSR1);
	}
}

void	loop(void)
{
	while (1)
	{
		pause();
		if (g_state.releasable_char == true)
		{
			if (g_state.c == 0)
			{
				write(1, "\n", 1);
				g_state.closed_transmission = true;
			}
			else
			{
				write(1, &g_state.c, 1);
			}
			g_state.c = 0;
			g_state.head_bit = 1 << 6;
			g_state.releasable_char = false;
		}
	}
}

void	display_pid(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID:", 4);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	bit_act;

	sigemptyset(&bit_act.sa_mask);
	bit_act.sa_sigaction = bit_handler;
	bit_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &bit_act, NULL) != 0)
	{
		ft_putstr_fd("Error in listenning signals", 1);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &bit_act, NULL) != 0)
	{
		ft_putstr_fd("Error in listenning signals", 1);
		exit(EXIT_FAILURE);
	}
	display_pid();
	loop();
	return (EXIT_SUCCESS);
}

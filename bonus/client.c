/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:59:19 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/22 15:22:40 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bit(int pid, char c)
{
	int	bit_index;

	bit_index = 1 << BIT_DIMENSION;
	while (bit_index)
	{
		if (bit_index & c)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Erreur lors de l'envoi du signal\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Erreur lors de l'envoi du signal\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		bit_index >>= 1;
		usleep(DELAY);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		char_to_bit(pid, message[i]);
		i++;
	}
	char_to_bit(pid, 0);
}

void	feedback(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	ft_putstr_fd("Message is transmitted successfully\n", 1);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putstr_fd("Error\nWrong argument number\n", 1);
		ft_putstr_fd("./client [PID] [MESSAGE]\n", 1);
		exit(EXIT_FAILURE);
	}
	act.sa_sigaction = feedback;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_putstr_fd("Error in listenning signals", 1);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
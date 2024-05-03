/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrigo <mabrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:08:42 by mabrigo           #+#    #+#             */
/*   Updated: 2024/05/02 20:51:43 by mabrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
SIGUSR1 = 1
SIGUSR2 = 0
*/

void	send_signal(int pid, char character)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (character & (1 << (7 - i)))
		{
			kill(pid, SIGUSR1);
			ft_printf("1[%d]\n", i);
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("0[%d]\n", i);
		}
		i++;
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int		i;

	i = 0;
	message = NULL;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
	}
	else
		ft_printf("Errore input\n");
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
		usleep(42);
	}
	send_signal(pid, '\0');
	return (0);
}

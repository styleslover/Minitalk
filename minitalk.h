/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrigo <mabrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:05:59 by mabrigo           #+#    #+#             */
/*   Updated: 2024/04/29 19:18:49 by mabrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef EOT
#  define EOT '\0'
# endif

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	handle_signal(int signal);
void	send_signal(int pid, char character);

#endif
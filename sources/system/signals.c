/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:28:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/26 19:13:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint_handler(int sig)
{
	(void)sig;
}

static void	sigquit_handler(int sig)
{
	(void)sig;
}

/* Self explanatory. */
void	handle_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	// sigint.sa_flags = SA_RESTART;
	sigint.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint, 0);
	// sigquit.sa_flags = SA_RESTART;
	sigquit.sa_handler = &sigquit_handler;
	sigaction(SIGQUIT, &sigquit, 0);
}

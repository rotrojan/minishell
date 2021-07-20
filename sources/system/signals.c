/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:28:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/18 20:21:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint_handler(int sig)
{
	int	stdout_copy;

	(void)sig;
	stdout_copy = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	write(STDIN_FILENO, "\n", 1);
	dup2(stdout_copy, STDOUT_FILENO);
	close(stdout_copy);
}

static void	sigquit_handler(int sig)
{
	(void)sig;
}

/* Self explanatory. */
void	handle_signals(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, &sigquit_handler);
}

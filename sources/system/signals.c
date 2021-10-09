/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:28:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/09 16:14:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_signal_on(void)
{
	static int	signal_on = 0;

	return (&signal_on);
}

void	set_signal_on(int sig)
{
	int	*signal_on;

	signal_on = get_signal_on();
	*signal_on = sig;
}

static void	sigint_handler(int sig)
{
	set_signal_on(sig);
	set_exit_value(EXIT_CTRL_C_VALUE);
}

static void	sigwinch_handler(int sig)
{
	set_signal_on(sig);
}

/* Self explanatory. */
void	handle_signals(void)
{
	signal(SIGTRAP, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGSEGV, SIG_DFL);
	signal(SIGBUS, SIG_DFL);
	signal(SIGABRT, SIG_DFL);
	signal(SIGINT, &sigint_handler);
	signal(SIGWINCH, &sigwinch_handler);
}

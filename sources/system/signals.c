/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:28:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/15 14:34:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_signum(void)
{
	static int	signum = 0;

	return (&signum);
}

void	set_signum(int sig)
{
	int	*signum;

	signum = get_signum();
	*signum = sig;
}

static void	sigint_handler(int sig)
{
	set_signum(sig);
	set_exit_value(EXIT_CTRL_C_VALUE);
}

static void	sigwinch_handler(int sig)
{
	set_signum(sig);
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

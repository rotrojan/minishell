/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:41:09 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/17 13:41:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

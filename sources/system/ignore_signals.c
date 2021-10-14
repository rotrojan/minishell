/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:44:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/14 21:29:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_signals(void)
{
	signal(SIGTRAP, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
	signal(SIGBUS, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGWINCH, SIG_IGN);
}

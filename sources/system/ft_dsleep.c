/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:39:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/02 16:34:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dsleep(int time)
{
	char			c;
	t_term			*term;

	signal(SIGINT, SIG_IGN);
	ft_fflush(STDIN_FILENO);
	term = getterm();
	set_timeout(term, time);
	read(STDIN_FILENO, &c, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	handle_signals();
}

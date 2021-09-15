/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:39:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/14 23:47:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dsleep(int time)
{
	char			c;
	t_term			*term;

	term = getterm();
	set_timeout(term, time);
	read(STDERR_FILENO, &c, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
}

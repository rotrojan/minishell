/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_timeout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:38:25 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/14 21:38:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_timeout(t_term *term, int timeout)
{
	struct termios	tmp;

	tmp = term->current;
	tmp.c_cc[VMIN] = 0;
	tmp.c_cc[VTIME] = timeout;
	tcsetattr(STDIN_FILENO, TCSANOW, &tmp);
}

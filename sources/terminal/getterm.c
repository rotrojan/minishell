/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:30:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 13:29:21 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return termios infos of terminal. */
t_term	*getterm(void)
{
	static t_term	term;

	return (&term);
}

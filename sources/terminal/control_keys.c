/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 04:38:24 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/26 04:47:07 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d_key(t_cursor *cursor)
{
	(void)cursor;
	ft_putstr_fd("\nexit\n", STDERR_FILENO);
	gc_exit(EXIT_SUCCESS, NULL);
}

/* Clear the screen. */
void	ctrl_l_key(t_cursor *cursor)
{
	char	*clear_cap;

	clear_cap = tgetstr("cl", NULL);
	tputs(clear_cap, 1, ft_putchar_err);
	prompt();
	print_inchars(inchars_head(cursor));
	cursor->pos = get_cursor_pos();
	cursor->on_inchar = inchars_queue(cursor);
}
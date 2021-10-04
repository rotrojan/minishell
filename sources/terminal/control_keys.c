/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 04:38:24 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/03 23:49:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d_input(void)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	gc_exit(*get_exit_value(), NULL);
}

void	ctrl_d_heredoc(char const *delimiter, int pos)
{
	ft_dprintf(STDERR_FILENO, "minishell: warning: here-document at line %d \
delimited by end-of-file (wanted `%s')\n", pos, delimiter);
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

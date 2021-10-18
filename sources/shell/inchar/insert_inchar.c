/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_inchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 07:43:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/18 22:08:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	manage_reprint(t_cursor *cursor)
{
	struct winsize	win;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	if (cursor->pos.x == win.ws_row - 1 && cursor->pos.y
		+ inchars_len(cursor, false) - 1 >= win.ws_col - 1)
	{
		tputs(tgetstr("sf", NULL), 1, ft_putchar_err);
		cursor->pos.x--;
	}
}

/* Insert char in input line. */
void	insert_inchar(t_cursor *cursor, int value)
{
	t_inchar		*new;
	t_history_data	*history;
	char			*goto_cap;

	history = get_history();
	new = create_inchar(value);
	new->prev = cursor->on_inchar->prev;
	if (cursor->on_inchar->prev != NULL)
		cursor->on_inchar->prev->next = new;
	new->next = cursor->on_inchar;
	cursor->on_inchar->prev = new;
	print_inchars(cursor->on_inchar->prev);
	cursor_move_right(cursor);
	manage_reprint(cursor);
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar_err);
	gc_free((void **)&history->input);
	history->input = inchars_to_line(cursor);
}

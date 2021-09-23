/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_inchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 07:43:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/23 01:07:22 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_inchar	*add_inchar(t_cursor *cursor, int value)
{
	t_inchar		*new;
	t_history_data	*history;

	history = get_history();
	new = create_inchar(value);
	new->prev = cursor->on_inchar->prev;
	if (cursor->on_inchar->prev != NULL)
		cursor->on_inchar->prev->next = new;
	new->next = cursor->on_inchar;
	cursor->on_inchar->prev = new;
	gc_free((void **)&history->input);
	history->input = inchars_to_line(inchars_head(cursor));
	return (new);
}

/* Insert char in input line. */
void	insert_inchar(t_cursor *cursor, int value)
{
	struct winsize	win;
	bool			ajust;

	ajust = false;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	cursor->on_inchar = add_inchar(cursor, value);
	ft_putchar_err(cursor->on_inchar->value);
	cursor->on_inchar = cursor->on_inchar->next;
	if (cursor->on_inchar->value != EOL)
	{
		if (cursor->pos.y == win.ws_col - 1)
		{
			ajust = true;
			ft_putchar_err(cursor->on_inchar->value);
			cursor_move_right(cursor);
		}
		if (ajust == true)
			tputs(tgetstr("le", NULL), 1, ft_putchar_err);
		tputs(tgetstr("sc", NULL), 1, ft_putchar_err);
		print_inchars(cursor->on_inchar);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	}
	if (ajust == false)
		cursor_move_right(cursor);
}

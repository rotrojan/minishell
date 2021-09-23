/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_inchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 07:43:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/24 01:05:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar_err);
	gc_free((void **)&history->input);
	history->input = inchars_to_line(inchars_head(cursor));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:43:48 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/22 21:18:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Move cursor to the left in line. */
void	left_arrow_key(t_cursor *cursor)
{
	char	*goto_cap;

	if (cursor->on_inchar->prev != NULL)
	{
		cursor->on_inchar = cursor->on_inchar->prev;
		cursor_move_left(cursor);
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar_err);
	}
}

/* Move cursor to the right in line. */
void	right_arrow_key(t_cursor *cursor)
{
	char	*goto_cap;

	if (cursor->on_inchar->next != NULL)
	{
		cursor->on_inchar = cursor->on_inchar->next;
		cursor_move_right(cursor);
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar_err);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:12:05 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/26 04:45:57 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Deletes the character in front of the cursor. */
void	backspace_key(t_cursor *cursor)
{
	char			*goto_cap;
	t_inchar		*tmp;
	t_history_data	*history;

	if (cursor->on_inchar->prev != NULL)
	{
		history = get_history();
		tmp = cursor->on_inchar->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = cursor->on_inchar;
		cursor->on_inchar->prev = tmp->prev;
		gc_free((void **)&tmp);
		cursor_move_left(cursor);
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar_err);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
		print_inchars(cursor->on_inchar);
		tputs(goto_cap, 1, ft_putchar_err);
		gc_free((void **)&history->input);
		history->input = inchars_to_line(inchars_head(cursor));
	}
}

/* Deletes the character in back of the cursor. */
void	delete_key(t_cursor *cursor)
{
	char			*goto_cap;
	t_inchar		*tmp;
	t_history_data	*history;

	if (cursor->on_inchar->value != EOL)
	{
		history = get_history();
		tmp = cursor->on_inchar->next;
		if (cursor->on_inchar->prev != NULL)
			cursor->on_inchar->prev->next = tmp;
		tmp->prev = cursor->on_inchar->prev;
		gc_free((void **)&cursor->on_inchar);
		cursor->on_inchar = tmp;
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
		print_inchars(cursor->on_inchar);
		tputs(goto_cap, 1, ft_putchar_err);
		gc_free((void **)&history->input);
		history->input = inchars_to_line(inchars_head(cursor));
	}
}

/* Move cursor to the start of line. */
void	home_key(t_cursor *cursor)
{
	char		*goto_cap;

	while (cursor->on_inchar->prev != NULL)
	{
		cursor_move_left(cursor);
		cursor->on_inchar = cursor->on_inchar->prev;
	}
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar_err);
}

/* Move cursor to the end of line. */
void	end_key(t_cursor *cursor)
{
	char		*goto_cap;

	while (cursor->on_inchar->next != NULL)
	{
		cursor_move_right(cursor);
		cursor->on_inchar = cursor->on_inchar->next;
	}
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar_err);
}

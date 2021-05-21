/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:12:05 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 13:44:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Deletes the character in front of the cursor. */
void	backspace_key(t_cursor *cursor)
{
	char		*goto_cap;
	t_inchar	*tmp;

	if (cursor->on_inchar->prev != NULL)
	{
		tmp = cursor->on_inchar->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = cursor->on_inchar;
		cursor->on_inchar->prev = tmp->prev;
		gc_free(tmp);
		cursor_move_left(cursor);
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar);
		ft_putxchar(' ', inchars_len(cursor->on_inchar));
		tputs(goto_cap, 1, ft_putchar);
		print_inchars(cursor->on_inchar);
		tputs(goto_cap, 1, ft_putchar);
	}
}

/* Deletes the character in back of the cursor. */
void	delete_key(t_cursor *cursor)
{
	char		*goto_cap;
	t_inchar	*tmp;

	if (cursor->on_inchar->value != EOL)
	{
		tmp = cursor->on_inchar->next;
		if (cursor->on_inchar->prev != NULL)
			cursor->on_inchar->prev->next = tmp;
		tmp->prev = cursor->on_inchar->prev;
		gc_free(cursor->on_inchar);
		cursor->on_inchar = tmp;
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		ft_putxchar(' ', inchars_len(cursor->on_inchar));
		tputs(goto_cap, 1, ft_putchar);
		print_inchars(cursor->on_inchar);
		tputs(goto_cap, 1, ft_putchar);
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
	tputs(goto_cap, 1, ft_putchar);
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
	tputs(goto_cap, 1, ft_putchar);
}

/* Clear the screen. */
void	ctrl_l_key(t_cursor *cursor)
{
	char	*clear_cap;

	clear_cap = tgetstr("cl", NULL);
	tputs(clear_cap, 1, ft_putchar);
	prompt();
	print_inchars(inchars_head(cursor));
	cursor->pos = get_cursor_pos();
}

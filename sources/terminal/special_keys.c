/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:12:05 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/17 18:26:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

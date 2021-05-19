/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:53:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:14:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_inchar	*create_inchar(int value)
{
	t_inchar	*inchar;

	inchar = gc_malloc(sizeof(t_inchar) * 1);
	inchar->value = value;
	inchar->next = NULL;
	inchar->prev = NULL;
	return (inchar);
}

void	clear_inchars(t_inchar **inchars)
{
	t_inchar	*tmp;
	t_inchar	*prev;

	tmp = *inchars;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		gc_free(prev);
	}
	*inchars = NULL;
}

void	insert_inchar(t_cursor *cursor, int value)
{
	char		*goto_cap;
	t_inchar	*new;

	new = create_inchar(value);
	new->prev = cursor->on_inchar->prev;
	if (cursor->on_inchar->prev != NULL)
		cursor->on_inchar->prev->next = new;
	new->next = cursor->on_inchar;
	cursor->on_inchar->prev = new;
	print_inchars(cursor->on_inchar->prev);
	cursor_move_right(cursor);
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar);
}

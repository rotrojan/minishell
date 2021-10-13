/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:56:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/13 10:52:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Self explanatory. */
t_history	*create_history(char *line)
{
	t_history	*history;

	history = gc_malloc(sizeof(t_history) * 1);
	history->line = line;
	history->next = NULL;
	history->prev = NULL;
	return (history);
}

/* Self explanatory. */
void	free_history(void)
{
	t_history		*tmp;
	t_history		*prev;
	t_history_data	*history;

	history = get_history();
	tmp = history->data;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		gc_free((void **)&prev);
	}
	history->data = NULL;
	history->tmp_nav = NULL;
	gc_free((void **)&history->input);
}

/* Self explanatory. */
void	push_front_history(t_history **history, char *line)
{
	t_history	*new;
	t_history	*tmp;

	tmp = *history;
	new = create_history(line);
	if (tmp != NULL)
	{
		new->next = tmp;
		tmp->prev = new;
	}
	*history = new;
}

/* Self explanatory. */
void	display_history(t_cursor *cursor, char *line)
{
	char		*goto_cap;
	t_inchar	*tmp;

	tmp = cursor->on_inchar;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		cursor_move_left(cursor);
	}
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar_err);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	tputs(goto_cap, 1, ft_putchar_err);
	cursor->on_inchar = line_to_inchars(line);
	while (cursor->on_inchar->next != NULL)
	{
		ft_putchar_err(cursor->on_inchar->value);
		cursor->on_inchar = cursor->on_inchar->next;
		cursor_move_right(cursor);
	}
}

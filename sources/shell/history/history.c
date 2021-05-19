/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 04:26:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 21:46:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_history_data	*get_history(void)
{
	static t_history_data	history;

	return (&history);
}

static void	display_history(t_cursor *cursor, t_history_data *history)
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
	tputs(goto_cap, 1, ft_putchar);
	ft_putxchar(' ', inchars_len(tmp));
	tputs(goto_cap, 1, ft_putchar);
	cursor->on_inchar = line_to_inchars(history->tmp_nav->line);
	print_inchars(cursor->on_inchar);
	cursor->on_inchar = inchars_queue(cursor);
	cursor->pos = get_cursor_pos();
}

void	history_get_up(t_cursor *cursor)
{
	int				len;
	t_history		*tmp;
	t_history_data	*history;

	history = get_history();
	if (history->data == NULL)
		return ;
	if (history->origine[0] == '\0')
	{
		display_history(cursor, history);
		if (history->tmp_nav->next != NULL)
			history->tmp_nav = history->tmp_nav->next;
	}
	else
	{
		len = ft_strlen(history->origine);
		tmp = history->tmp_nav;
		while (tmp != NULL && ft_strncmp(tmp->line, history->origine, len) != 0)
			tmp = tmp->next;
		if (tmp != NULL)
		{
			history->tmp_nav = tmp;
			display_history(cursor, history);
		}
	}
}

// void	history_get_down(t_cursor *cursor)
// {
// 	t_history_data	*history;

// 	history = get_history();
// 	if (history->data == NULL)
// 		return ;
// }

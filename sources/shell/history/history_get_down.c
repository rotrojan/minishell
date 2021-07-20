/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_get_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 03:31:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/18 19:19:52 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_prev(t_cursor *cursor, t_history_data *history)
{
	if (history->tmp_nav != NULL)
	{
		if (history->tmp_nav->prev == NULL)
		{
			history->tmp_nav = NULL;
			display_history(cursor, history->input);
		}
		else
		{
			if (history->tmp_nav->prev != NULL)
				history->tmp_nav = history->tmp_nav->prev;
			display_history(cursor, history->tmp_nav->line);
		}
	}
}

static void	search_prev(t_cursor *cursor, t_history_data *history)
{
	int				len;
	t_history		*tmp;

	tmp = NULL;
	len = ft_strlen(history->input);
	if (history->tmp_nav == NULL)
		tmp = history->data;
	else if (history->tmp_nav->prev != NULL)
		tmp = history->tmp_nav->prev;
	while (tmp != NULL && ft_strncmp(tmp->line, history->input, len) != 0)
		tmp = tmp->prev;
	if (tmp != NULL)
	{
		history->tmp_nav = tmp;
		display_history(cursor, history->tmp_nav->line);
	}
	else
		display_history(cursor, history->input);
}

/* Get previous line in history. */
void	history_get_down(t_cursor *cursor)
{
	t_history_data	*history;

	history = get_history();
	if (history->data == NULL)
		return ;
	else if (history->input[0] == '\0')
		go_prev(cursor, history);
	else
		search_prev(cursor, history);
}

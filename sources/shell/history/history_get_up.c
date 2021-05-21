/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_get_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 03:29:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 15:10:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_next(t_cursor *cursor, t_history_data *history)
{
	if (history->tmp_nav == NULL)
		history->tmp_nav = history->data;
	else if (history->tmp_nav->next != NULL)
		history->tmp_nav = history->tmp_nav->next;
	display_history(cursor, history->tmp_nav->line);
}

static void	search_next(t_cursor *cursor, t_history_data *history)
{
	int				len;
	t_history		*tmp;

	tmp = NULL;
	len = ft_strlen(history->input);
	if (history->tmp_nav == NULL)
		tmp = history->data;
	else if (history->tmp_nav->next != NULL)
		tmp = history->tmp_nav->next;
	while (tmp != NULL && ft_strncmp(tmp->line, history->input, len) != 0)
		tmp = tmp->next;
	if (tmp != NULL)
	{
		history->tmp_nav = tmp;
		display_history(cursor, history->tmp_nav->line);
	}	
}

/* Get next line in history. */
void	history_get_up(t_cursor *cursor)
{
	t_history_data	*history;

	history = get_history();
	if (history->data == NULL)
		return ;
	if (history->input[0] == '\0')
		go_next(cursor, history);
	else
		search_next(cursor, history);
}

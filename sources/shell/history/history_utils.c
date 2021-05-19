/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:56:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 21:11:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_history	*create_history(char *line)
{
	t_history	*history;

	history = gc_alloc(sizeof(t_history) * 1);
	history->line = line;
	history->next = NULL;
	history->prev = NULL;
	return (history);
}

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
		gc_free(prev);
	}
	history->data = NULL;
	history->tmp_nav = NULL;
	gc_free(history->origine);
}

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

t_history_data	*init_history(void)
{
	int				fd;
	char			*line;
	t_history_data	*history;

	line = NULL;
	history = get_history();
	history->data = NULL;
	history->origine = ft_strdup("");
	fd = open(HISTORY_PATH, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) > 0)
			if (line != NULL)
				push_front_history(&history->data, line);
		close(fd);
		history->tmp_nav = history->data;
	}
	return (history);
}

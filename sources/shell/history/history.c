/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 04:26:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:15:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_history	**get_history(void)
{
	static t_history	*history = NULL;

	return (&history);
}

t_history	*create_history(char *line)
{
	t_history	*history;

	history = gc_malloc(sizeof(t_history) * 1);
	history->line = line;
	history->next = NULL;
	history->prev = NULL;
	return (history);
}

void	clear_history(t_history **history)
{
	t_history	*tmp;
	t_history	*prev;

	tmp = *history;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		gc_free(prev);
	}
	*history = NULL;
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

t_history	**init_history(void)
{
	int			fd;
	char		*line;
	t_history	**history;

	line = NULL;
	history = get_history();
	fd = open(HISTORY_PATH, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) > 0)
			if (line != NULL)
				push_front_history(history, line);
	}
	close(fd);
	return (history);
}

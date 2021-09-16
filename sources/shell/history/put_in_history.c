/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:06:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/16 03:33:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_history	*search_in_history(t_history_data *history, char *line)
{
	t_history	*tmp;

	tmp = history->data;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->line, line) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	add_in_history(t_history_data *history, char *line)
{
	int	fd;

	fd = open(HISTORY_PATH, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd <= 0)
		exit_shell(EXIT_FAILURE, "open(): can't open .minish_history file.\n");
	ft_dprintf(fd, "%s\n", line);
	push_front_history(&history->data, line);
	close(fd);
}

static void	move_elem_at_front(t_history_data *history, t_history *element)
{
	t_history	*tmp;

	tmp = history->data;
	if (element->prev != NULL)
		element->prev->next = element->next;
	if (element->next != NULL)
		element->next->prev = element->prev;
	if (tmp != element)
	{
		element->next = tmp;
		tmp->prev = element;
		element->prev = NULL;
		history->data = element;
	}
}

static void	re_add_in_history(t_history_data *history, t_history *element)
{
	int			fd;
	t_history	*tmp;

	move_elem_at_front(history, element);
	fd = open(HISTORY_PATH, O_WRONLY);
	if (fd <= 0)
		exit_shell(EXIT_FAILURE, "open(): can't open .minish_history file.\n");
	tmp = history->data;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		ft_dprintf(fd, "%s\n", tmp->line);
		tmp = tmp->prev;
	}
	close(fd);
}

/* Save line in history data. */
void	put_in_history(char *line)
{
	t_history		*already_in;
	t_history_data	*history;

	history = get_history();
	already_in = search_in_history(history, line);
	if (already_in != NULL)
	{
		if (ft_strcmp(line, history->data->line) != 0)
			re_add_in_history(history, already_in);
	}
	else
		add_in_history(history, line);
	reset_history_data();
}

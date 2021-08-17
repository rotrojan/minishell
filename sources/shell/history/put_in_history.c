/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:06:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/17 16:00:57 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_in_history(t_history_data *history, char *line)
{
	int	fd;

	fd = open(HISTORY_PATH, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd <= 0)
		exit_shell(EXIT_FAILURE, "open(): can't open .minish_history file.\n");
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	push_front_history(&history->data, line);
	close(fd);
}

/* Save line in history data. */
void	put_in_history(char *line)
{
	t_history_data	*history;

	history = get_history();
	if (history->data == NULL)
		add_in_history(history, line);
	else if (ft_strcmp(line, history->data->line) != 0)
		add_in_history(history, line);
	history->tmp_nav = NULL;
	gc_free(history->input);
	history->input = ft_strdup("");
}

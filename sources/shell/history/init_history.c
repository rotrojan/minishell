/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:29:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/18 23:36:55 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_history_data(void)
{
	free_history();
	init_history();
}

static char	*get_history_path(void)
{
	char	*home;

	home = ft_getenv("HOME");
	if (home == NULL)
		return (ft_strjoin("/tmp/", HISTORY_FILE, ""));
	else
		return (ft_strjoin(home, HISTORY_FILE, "/"));
}

/* Read HISTORY_FILE and save it in accessible memory. */
t_history_data	*init_history(void)
{
	int				fd;
	char			*line;
	t_history_data	*history;
	char			*history_path;

	line = NULL;
	history = get_history();
	history->input = NULL;
	history_path = get_history_path();
	fd = open(history_path, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (line[0] != '\0')
				push_front_history(&history->data, line);
			else
				gc_free((void **)&line);
			line = NULL;
		}
		close(fd);
	}
	gc_free((void **)&history_path);
	return (history);
}

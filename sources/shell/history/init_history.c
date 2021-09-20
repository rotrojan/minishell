/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:29:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/16 03:31:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_history_data(void)
{
	t_history_data	*history;

	history = get_history();
	history->tmp_nav = NULL;
	gc_free((void **)&history->input);
	history->input = ft_strdup("");
}

/* Read HISTORY_PATH and save it in accessible memory. */
t_history_data	*init_history(void)
{
	int				fd;
	char			*line;
	t_history_data	*history;

	line = NULL;
	history = get_history();
	history->input = ft_strdup("");
	fd = open(HISTORY_PATH, O_RDONLY);
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
	return (history);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:06:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 21:12:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_in_history(char *line)
{
	int				fd;
	t_history_data	*history;

	history = get_history();
	fd = open(HISTORY_PATH, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd <= 0)
		exit_shell(EXIT_FAILURE, "open(): can't open .minish_history file.\n");
	ft_fprintf(fd, "%s\n", line);
	push_front_history(&history->data, line);
	history->tmp_nav = history->data;
	gc_free(history->origine);
	history->origine = ft_strdup("");
	close(fd);
}

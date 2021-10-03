/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:32:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/03 02:54:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	append_input(char **doc, char *line)
{
	char	*tmp;

	tmp = *doc;
	if (tmp == NULL)
		*doc = ft_strdup(line);
	else
		*doc = ft_strjoin(tmp, line, "\n");
	gc_free((void **)&tmp);
	gc_free((void **)&line);
}

char	*heredoc(const char *delimiter)
{
	char	*line;
	char	*doc;

	doc = NULL;
	reset_history_data();
	while (1)
	{
		ft_putstr_fd("> ", STDERR_FILENO);
		line = ft_readline();
		reset_history_data();
		if (*get_signal_on() == SIGINT)
		{
			gc_free((void **)&doc);
			return (NULL);
		}
		ft_putchar_fd('\n', STDERR_FILENO);
		if (line != NULL && ft_strcmp(line, delimiter) == 0)
			break ;
		append_input(&doc, line);
	}
	append_input(&doc, NULL);
	return (doc);
}

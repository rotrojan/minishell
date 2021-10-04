/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:32:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/04 08:25:33 by lucocozz         ###   ########.fr       */
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

static bool	catch_sigint(char *doc, char *line)
{
	if (*get_signal_on() == SIGINT)
	{
		gc_free((void **)&line);
		gc_free((void **)&doc);
		return (true);
	}
	return (false);
}

static bool	heredoc_control(char const *delimiter, char *line, int pos)
{
	if (line != NULL)
	{
		if (line[0] == EOF)
		{
			ctrl_d_heredoc(delimiter, pos);
			return (true);
		}
		if (ft_strcmp(line, delimiter) == 0)
			return (true);
		return (false);
	}
	return (false);
}

char	*heredoc(char const *delimiter)
{
	char	*line;
	char	*doc;
	t_axe	pos;

	doc = NULL;
	pos = get_cursor_pos();
	reset_history_data();
	while (true)
	{
		ft_putstr_fd("> ", STDERR_FILENO);
		line = ft_readline();
		reset_history_data();
		if (catch_sigint(doc, line) == true)
			return (NULL);
		ft_putchar_fd('\n', STDERR_FILENO);
		if (heredoc_control(delimiter, line, pos.x) == true)
			break ;
		append_input(&doc, line);
	}
	gc_free((void **)&line);
	append_input(&doc, NULL);
	return (doc);
}

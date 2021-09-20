/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:32:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/19 02:29:05 by lucocozz         ###   ########.fr       */
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
}

char	*heredoc(const char *delimiter)
{
	char	*line;
	char	*doc;
	t_term	*term;

	doc = NULL;
	line = NULL;
	term = set_termios();
	reset_history_data();
	while (1)
	{
		ft_putstr("> ");
		line = input();
		reset_history_data();
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		if (*line != '\0')
			append_input(&doc, line);
		gc_free((void **)&line);
		ft_putstr_fd("\r\n", STDERR_FILENO);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
	ft_putchar('\n');
	append_input(&doc, NULL);
	return (doc);
}

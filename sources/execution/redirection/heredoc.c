/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:32:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/09 23:47:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc(const char *delimiter)
{
	char	*line;
	char	*doc;
	char	*tmp;
	t_term	*term;

	doc = NULL;
	line = NULL;
	term = set_termios();
	while (1)
	{
		ft_putstr("> ");
		line = input();
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		if (*line == '\0')
		{
			tmp = doc;
			doc = ft_strjoin(tmp, line, "\n");
			gc_free((void **)&tmp);
		}
		gc_free((void **)&line);
	}
		tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
	return (doc);
}

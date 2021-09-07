/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:32:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/06 19:36:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(const char *delimiter)
{
	char	*line;
	char	*doc;
	char	*tmp;

	doc = NULL;
	line = NULL;
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
	ft_putstr_fd(doc, STDIN_FILENO);
}

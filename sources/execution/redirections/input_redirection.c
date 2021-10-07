/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:29:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/04 01:42:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_redirection(t_redirection *redirection)
{
	char	*doc;
	int		fd[2];

	doc = heredoc(redirection->stream);
	if (doc == NULL)
	{
		set_exit_value(EXIT_CTRL_C_VALUE);
		return (-1);
	}
	if (redirection->has_quotes == false && doc != NULL)
		expand_vars_in_stream(&doc);
	if (pipe(fd) == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	if (doc != NULL)
		ft_putstr_fd(doc, fd[Input]);
	dup2(fd[Output], STDIN_FILENO);
	close(fd[Input]);
	close(fd[Output]);
	gc_free((void **)&doc);
	return (0);
}

static int	simple_redirection(t_redirection *redirection)
{
	redirection->fd = open(redirection->stream, O_RDONLY);
	if (redirection->fd < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: No such file or directory\n",
			redirection->stream);
		set_exit_value(EXIT_FAILURE);
		return (-1);
	}
	redirection->isopen = true;
	dup2(redirection->fd, STDIN_FILENO);
	return (0);
}

static t_redirection	*foreward_input(t_redirection *redirection)
{
	char	*doc;

	while (redirection->next != NULL)
	{
		if (redirection->type == Heredoc_redir)
		{
			doc = heredoc(redirection->stream);
			gc_free((void **)&doc);
		}
		redirection = redirection->next;
	}
	return (redirection);
}

int	input_redirection(t_redirection *redirection)
{
	redirection = foreward_input(redirection);
	if (redirection->type == Heredoc_redir)
	{
		if (heredoc_redirection(redirection) == -1)
			return (-1);
	}
	else if (simple_redirection(redirection) == -1)
		return (-1);
	return (0);
}

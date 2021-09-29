/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:29:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 04:08:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_redirection(t_redirection *redirection)
{
	char	*doc;
	int		fd[2];

	doc = heredoc(redirection->stream);
	if (redirection->has_quotes == false)
		expand_vars_in_stream(&doc);
	if (pipe(fd) == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	ft_putstr_fd(doc, fd[Input]);
	dup2(fd[Output], STDIN_FILENO);
	close(fd[Input]);
	close(fd[Output]);
	gc_free((void **)&doc);
}

static int	simple_redirection(t_redirection *redirection)
{
	char	*path;
	DIR		*dir;

	path = extract_path(redirection->stream);
	dir = opendir(path);
	if (dir == NULL && errno == ENOENT)
		ft_dprintf(STDERR_FILENO, "minishell: %s: Stale file handle\n",
			redirection->stream);
	else
		closedir(dir);
	gc_free((void **)&path);
	redirection->fd = open(redirection->stream, O_RDONLY);
	if (redirection->fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", redirection->stream,
			strerror(errno));
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
		heredoc_redirection(redirection);
	else if (simple_redirection(redirection) == -1)
		return (-1);
	return (0);
}

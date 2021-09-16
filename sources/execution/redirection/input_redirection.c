/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:29:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/16 05:39:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_redirection(t_redirection *redirection)
{
	char	*doc;

	reset_history_data();
	doc = heredoc(redirection->stream);
	redirection->fd = open("./", __O_TMPFILE | O_RDWR, 0644);
	if (redirection->fd == -1)
		exit_shell(EXIT_FAILURE, "Error: heredoc(): can't create tmp file");
	redirection->isopen = true;
	ft_putchar_err('\n');
	ft_putstr_fd(doc, redirection->fd);
	dup2(redirection->fd, STDIN_FILENO);
	gc_free((void **)&doc);
}

static int	simple_redirection(t_redirection *redirection)
{
	redirection->fd = open(redirection->stream, O_RDONLY);
	if (redirection->fd == -1)
	{
		ft_dprintf(STDOUT_FILENO, "minishell: %s: No such file or directory\n",
			redirection->stream);
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
	else
		if (simple_redirection(redirection) == -1)
			return (-1);
	return (0);
}

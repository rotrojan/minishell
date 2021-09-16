/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:19:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/16 04:37:05 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file(t_redirection *redirection)
{
	int	flag;

	if (redirection->type == Output_redir)
		flag = O_TRUNC;
	else
		flag = O_APPEND;
	redirection->fd = open(redirection->stream, O_WRONLY | O_CREAT | flag,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (redirection->fd == -1)
	{
		ft_dprintf(STDOUT_FILENO, "minishell: %s: No such file or directory\n",
			redirection->stream);
		return (-1);
	}
	redirection->isopen = true;
	return (0);
}

int	output_redirection(t_redirection *redirection)
{
	if (open_file(redirection) == -1)
		return (-1);
	dup2(redirection->fd, STDOUT_FILENO);
	redirection = redirection->next;
	while (redirection != NULL)
	{
		if (redirection->type == Output_redir)
		{
			if (open_file(redirection) == -1)
				return (-1);
			close(redirection->fd);
			redirection->isopen = false;
		}
		redirection = redirection->next;
	}
	return (0);
}

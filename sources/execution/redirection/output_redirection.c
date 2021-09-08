/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:19:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/08 03:59:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file(t_redirection *redirection)
{
	int	fd;

	fd = open(redirection->stream, O_WRONLY | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		ft_dprintf(STDOUT_FILENO, "minishell: %s: No such file or directory\n",
			redirection->stream);
		return (-1);
	}
	return (fd);
}

int	output_redirection(t_redirection *redirection)
{
	int	fd;
	int	tmp;

	fd = open_file(redirection);
	if (fd == -1)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	redirection = redirection->next;
	while (redirection != NULL)
	{
		if (redirection->type == Output_redir)
		{
			tmp = open_file(redirection);
			if (tmp == -1)
				return (-1);
			close(tmp);
		}
		redirection = redirection->next;
	}
	return (0);
}

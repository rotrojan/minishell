/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:08:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/19 02:30:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_redirections(t_redirection *redirection)
{
	while (redirection != NULL)
	{
		if (redirection->isopen == true)
		{
			close(redirection->fd);
			redirection->isopen = false;
			if (redirection->type == Heredoc_redir && redirection->next == NULL)
				unlink(HEREDOC_PATH);
		}
		redirection = redirection->next;
	}
}

int	redirection(t_simple_cmd command)
{
	t_redirection		*input_redir;
	t_redirection		*output_redir;

	input_redir = command.input_redir;
	if (input_redir != NULL)
		if (input_redirection(input_redir) == -1)
			return (-1);
	output_redir = command.output_redir;
	if (output_redir != NULL)
		if (output_redirection(output_redir) == -1)
			return (-1);
	return (0);
}

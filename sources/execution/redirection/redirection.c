/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:08:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/08 03:49:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection(t_simple_cmd command)
{
	int					i;
	t_redirection		*redirection;
	const t_redir_func	match[] = {
		{.type = Input_redir, .function = &input_redirection},
		{.type = Output_redir, .function = &output_redirection},
		// {.type = Append_output_redir, .function = &append_redirection},
		// {.type = Heredoc_redir, .function = &heredoc_redirection},
		{.type = No_redir}
	};

	i = 0;
	redirection = command.redirection;
	if (redirection == NULL)
		return (0);
	while (match[i].type != redirection->type && match[i].type != No_redir)
		i++;
	if (match[i].type == No_redir)
		return (0);
	if (match[i].function(redirection) == -1)
		return (-1);
	return (0);
}

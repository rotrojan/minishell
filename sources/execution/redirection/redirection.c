/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:08:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/09 23:26:23 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

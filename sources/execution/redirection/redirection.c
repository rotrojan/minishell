/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:08:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 21:08:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection(t_simple_cmd command)
{
	t_redirection	*redirection;

	redirection = command.redirection;
	if (redirection == NULL)
		return (0);
	while (redirection->type != Input_redir
		&& redirection->type != Output_redir)
		redirection = redirection->next;
	if (redirection->type == Input_redir)
	{
		if (input_redirection(redirection) == -1)
			return (-1);
	}
	else if (redirection->type == Output_redir)
	{
		if (output_redirection(redirection) == -1)
			return (-1);
	}
	return (0);
}

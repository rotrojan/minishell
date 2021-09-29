/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/30 01:19:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	handle_redirections(t_simple_cmd *cmd)
{
	t_redirection	*redir_lst;

	redir_lst = cmd->input_redir;
	while (redir_lst != NULL)
	{
		if (expand_vars_in_stream(&redir_lst->stream) == false)
		{
			set_exit_value(EXIT_FAILURE);
			return (false);
		}
		remove_quotes_from_arg(&redir_lst->stream);
		redir_lst = redir_lst->next;
	}
	redir_lst = cmd->output_redir;
	while (redir_lst != NULL)
	{
		if (expand_vars_in_stream(&redir_lst->stream) == false)
		{
			set_exit_value(EXIT_FAILURE);
			return (false);
		}
		remove_quotes_from_arg(&redir_lst->stream);
		redir_lst = redir_lst->next;
	}
	return (true);
}

bool	perform_expansions(t_simple_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[i] != NULL)
	{
		if (ft_strchr(cmd->argv[i], '$') != NULL)
			expand_vars(cmd, i);
		remove_quotes_from_arg(&cmd->argv[i]);
		++i;
	}
	return (handle_redirections(cmd));
}

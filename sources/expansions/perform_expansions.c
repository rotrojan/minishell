/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/14 14:49:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_vars(t_simple_cmd *cmd, int const i)
{
	int		j;
	bool	in_squotes;
	bool	in_dquotes;

	j = 0;
	in_squotes = false;
	in_dquotes = false;
	while (cmd->argv[i] != NULL && cmd->argv[i][j] != '\0')
	{
		if (cmd->argv[i][j] == '$' && in_squotes == false)
		{
			if (cmd->argv[i][j + 1] == '\0'
					|| ft_isalnum(cmd->argv[i][j + 1]) == 0)
				cmd->argv[i] = fill_new_arg(&cmd->argv[i], 0, j++, "$");
			else
				expand_single_var(cmd, i, &j, in_dquotes);
		}
		else
		{
			change_quote_state(cmd->argv[i][j], &in_squotes, &in_dquotes);
			++j;
		}
	}
}

void	perform_expansions_on_redirections(t_simple_cmd *cmd)
{
	t_redirection	*current;

	current = cmd->input_redir;
	while (current != NULL)
	{
		current = current->next;
	}
	current = cmd->output_redir;
	while (current != NULL)
	{
		current = current->next;
	}

}

void	perform_expansions(t_simple_cmd *cmd)
{
	int				i;

	i = 0;
	while (cmd->argv[i] != NULL)
	{
		if (ft_strchr(cmd->argv[i], '$') != NULL)
			expand_vars(cmd, i);
		remove_quotes_from_arg(&cmd->argv[i]);
		++i;
	}
	perform_expansions_on_redirections(cmd);
}

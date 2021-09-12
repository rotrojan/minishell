/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/12 14:03:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_quote_state(char quote, bool *in_squotes, bool *in_dquotes)
{
	if (quote == '\'' && *in_dquotes == true)
		*in_squotes = (*in_squotes == false);
	else if (quote == '"' && *in_squotes == true)
		*in_dquotes = (*in_dquotes == false);
}

static void	expand_vars(t_simple_cmd *cmd, int *i)
{
	int		j;
	bool	in_squotes;
	bool	in_dquotes;

	j = 0;
	in_squotes = false;
	in_dquotes = false;
	while (cmd->argv[*i][j] != '\0')
	{
		if (cmd->argv[*i][j] == '$' && in_squotes == false)
		{
			if (cmd->argv[*i][j + 1] == '\0'
					|| ft_isalnum(cmd->argv[*i][j + 1]) == 0)
				cmd->argv[*i] = fill_new_arg(&cmd->argv[*i], 0, j++, "$");
			else
				expand_single_var(cmd, i, &j, in_dquotes);
		}
		else
		{
			change_quote_state(cmd->argv[*i][j], &in_squotes, &in_dquotes);
			++j;
		}
	}
}

void	perform_expansions(t_simple_cmd *cmd)
{
	int				i;
	t_redirection	*redir_lst;

	redir_lst = cmd->redirection;
	i = 0;
	while (cmd->argv[i] != NULL)
	{
		if (ft_strchr(cmd->argv[i], '$') != NULL)
			expand_vars(cmd, &i);
		/* remove_quotes() */
		/* else */
		++i;
	}
	while (redir_lst != NULL)
	{
		/* expand_vars(&(redir_lst->stream)); */
		redir_lst = redir_lst->next;
	}
}

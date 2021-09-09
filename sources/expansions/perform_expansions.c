/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/09 23:28:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	perform_expansions(t_simple_cmd *cmd)
{
	char			**argv;
	int				i;
	t_redirection	*redir_lst;

	argv = cmd->argv;
	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], '$'))
			expand_vars(&argv[i]);
		/* remove_quotes() */
		++i;
	}
	redir_lst = cmd->input_redir;
	while (redir_lst != NULL)
	{
		expand_vars(&(redir_lst->stream));
		redir_lst = redir_lst->next;
		/* remove_quotes() */
	}
	redir_lst = cmd->output_redir;
	while (redir_lst != NULL)
	{
		expand_vars(&(redir_lst->stream));
		redir_lst = redir_lst->next;
		/* remove_quotes() */
	}
}

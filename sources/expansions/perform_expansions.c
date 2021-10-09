/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:57:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/09 18:33:44 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	perform_expansions(t_simple_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[i] != NULL)
	{
		if (ft_strchr(cmd->argv[i], '$') != NULL)
			if (expand_vars(cmd, i) == false)
				return (false);
		++i;
	}
	if (expand_wildcard(cmd) == false)
		return (false);
	i = 0;
	while (cmd->argv[i] != NULL)
	{
		if (ft_strcmp(cmd->argv[i], "<<") == 0)
			cmd->input_stream_has_quotes
				= (ft_strchr(cmd->argv[i + 1], '\'') != NULL
					|| ft_strchr(cmd->argv[i + 1], '"') != NULL);
		remove_quotes_from_arg(&cmd->argv[i]);
		++i;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:54:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/13 13:00:27 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_and_redir_and_exec(t_node *ast, bool is_piped)
{
	if (perform_expansions(ast) == true)
	{
		if (exec_redirections(ast) == true)
		{
			if (is_piped == false)
			{
				if (*get_signal_on() != SIGINT)
					exec_simple_cmd(ast->content.simple_cmd);
			}
			else
				exec_pipe(ast);
		}
		else
			set_exit_value(EXIT_FAILURE);
	}
	else
		set_exit_value(EXIT_FAILURE);
}

void	exec_ast(t_node *ast, bool inline_mode)
{
	if (inline_mode == false)
		ft_putstr_fd("\n\r", STDERR_FILENO);
	if (ast->type == Simple_cmd)
		expand_and_redir_and_exec(ast, false);
	else if (ast->type == Pipe_node)
	{
		set_is_piped(true);
		expand_and_redir_and_exec(ast, true);
		set_is_piped(false);
	}
	else
		exec_list_cmd(ast);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:54:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/09 15:54:06 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_ast(t_node *ast, bool inline_mode)
{
	if (inline_mode == false)
		ft_putstr_fd("\n\r", STDERR_FILENO);
	if (ast->type == Simple_cmd)
	{
		if (*get_signal_on() != SIGINT)
			exec_simple_cmd(ast->content.simple_cmd);
	}
	else if (ast->type == Pipe_node)
	{
		set_is_piped(true);
		exec_pipe(ast);
		set_is_piped(false);
	}
	else
		exec_list_cmd(ast);
}

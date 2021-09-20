/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:54:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/20 23:13:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_ast(t_node *ast, bool inline_mode)
{
	if (inline_mode == false)
		ft_putstr_fd("\n\r", STDERR_FILENO);
	if (ast->type == Simple_cmd)
	{
		if (perform_expansions(&ast->content.simple_cmd) == false)
			return ;
		exec_simple_cmd(ast->content.simple_cmd);
	}
	else if (ast->type == Pipe_node)
		exec_pipe(ast);
}

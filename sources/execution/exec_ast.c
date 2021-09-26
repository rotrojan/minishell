/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:54:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/26 10:36:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	catch_signals(void)
{
	int	*sig;
	int	tmp;

	sig = get_signal_on();
	tmp = *sig;
	*sig = 0;
	return (tmp);
}

void	exec_ast(t_node *ast, bool inline_mode)
{
	if (inline_mode == false)
		ft_putstr_fd("\n\r", STDERR_FILENO);
	if (ast->type == Simple_cmd)
	{
		if (perform_expansions(&ast->content.simple_cmd) == false)
			return ;
		if (catch_signals() != SIGINT)
			exec_simple_cmd(ast->content.simple_cmd);
	}
	else if (ast->type == Pipe_node)
		exec_pipe(ast);
	else
		exec_compound_cmd(ast);
}

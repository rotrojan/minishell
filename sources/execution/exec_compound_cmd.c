/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_compound_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:52:45 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/22 01:12:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_semic_node(t_node *ast)
{
	exec_ast(ast->content.child.left, true);
	exec_ast(ast->content.child.right, true);
}

static void	exec_or_node(t_node *ast)
{
	exec_ast(ast->content.child.left, true);
	if (*get_exit_value() != 0)
		exec_ast(ast->content.child.right, true);
}

static void	exec_and_node(t_node *ast)
{
	exec_ast(ast->content.child.left, true);
	if (*get_exit_value() == 0)
		exec_ast(ast->content.child.right, true);
}

void	exec_compound_cmd(t_node *ast)
{
	if (ast->type == And_node)
		exec_and_node(ast);
	else if (ast->type == Or_node)
		exec_or_node(ast);
	else
		exec_semic_node(ast);
}

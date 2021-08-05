/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:54:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/05 03:29:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_ast(t_node *ast)
{
	ft_fputstr(STDERR_FILENO, "\n\r");
	if (ast->type == Simple_cmd)
		exec_simple_cmd(ast->content.simple_cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:56:04 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/06 18:01:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Free the simple command leaf in the AST using gc_free from the libgc.
*/

static void	free_simple_cmd(t_node **simple_cmd)
{
	int		i;

	i = 0;
	if (*simple_cmd != NULL)
	{
		i = 0;
		while ((*simple_cmd)->content.simple_cmd.argv[i] != NULL)
		{
			gc_free((void **)&(*simple_cmd)->content.simple_cmd.argv[i]);
			++i;
		}
		gc_free((void **)&(*simple_cmd)->content.simple_cmd.argv);
		gc_free((void **)&*simple_cmd);
	}
}

/*
** Free the AST using gc_free from the libgc.
*/

void	clear_ast(t_node **ast)
{
	if (*ast == NULL)
		return ;
	if ((*ast)->type == Simple_cmd)
		free_simple_cmd(ast);
	else
	{
		clear_ast(&((*ast)->content.child.left));
		clear_ast(&((*ast)->content.child.right));
		gc_free((void **)&*ast);
	}
}

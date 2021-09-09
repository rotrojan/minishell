/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:56:04 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/09 23:21:57 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Free the redirections linked list in the simple command leaf in the AST using
** gc_free from the libgc.
*/

static void	free_redirections(t_redirection **redirection_lst)
{
	t_redirection	*prev;
	t_redirection	*current;

	if (*redirection_lst == NULL)
		return ;
	current = *redirection_lst;
	while (current != NULL)
	{
		gc_free((void **)&current->stream);
		prev = current;
		current = current->next;
		gc_free((void **)&prev);
	}
}

/*
** Free the simple command leaf in the AST using gc_free from the libgc.
*/

static void	free_simple_cmd(t_node **simple_cmd)
{
	int		i;

	i = 0;
	if (*simple_cmd == NULL)
		return ;
	i = 0;
	while ((*simple_cmd)->content.simple_cmd.argv[i] != NULL)
	{
		gc_free((void **)&(*simple_cmd)->content.simple_cmd.argv[i]);
		++i;
	}
	gc_free((void **)&(*simple_cmd)->content.simple_cmd.argv);
	free_redirections(&((*simple_cmd)->content.simple_cmd.input_redir));
	free_redirections(&((*simple_cmd)->content.simple_cmd.output_redir));
	gc_free((void **)&*simple_cmd);
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

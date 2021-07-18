/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:56:04 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/18 20:20:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_redirections(t_redirection **redirection_lst)
{
	t_redirection	*prev;
	t_redirection	*current;

	if (*redirection_lst == NULL)
		return ;
	current = *redirection_lst;
	while (current != NULL)
	{
		gc_free(current->stream);
		current->stream = NULL;
		prev = current;
		current = current->next;
		gc_free(prev);
	}
}

static void	free_simple_cmd(t_node **simple_cmd)
{
	int		i;

	i = 0;
	if (*simple_cmd == NULL)
		return ;
	i = 0;
	while ((*simple_cmd)->content.simple_cmd.argv[i] != NULL)
	{
		gc_free((*simple_cmd)->content.simple_cmd.argv[i]);
		(*simple_cmd)->content.simple_cmd.argv[i] = NULL;
		++i;
	}
	gc_free((*simple_cmd)->content.simple_cmd.argv);
	(*simple_cmd)->content.simple_cmd.argv = NULL;
	free_redirections(&((*simple_cmd)->content.simple_cmd.redirection));
	gc_free(*simple_cmd);
	*simple_cmd = NULL;
}

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
	}
}

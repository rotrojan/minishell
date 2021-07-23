/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/23 18:40:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	parse_pipe(t_token **tok_lst, t_node **ast)
{
	t_node	*pipe_node;

	if (*ast == NULL)
		return (False);
	pipe_node = NULL;
	pipe_node = gc_malloc(sizeof(*pipe_node));
	ft_bzero(pipe_node, sizeof(*pipe_node));
	pipe_node->type = Pipe_node;
	pipe_node->content.child.left = *ast;
	*ast = pipe_node;
	eat_token(tok_lst);
	return (parse_simple_cmd(tok_lst, &((*ast)->content.child.right)));
}

t_bool	parse_logical_operator(t_token **tok_lst, t_node **ast)
{
	t_node	*logical_operator_node;

	if (*ast == NULL)
		return (False);
	logical_operator_node = NULL;
	logical_operator_node = gc_malloc(sizeof(*logical_operator_node));
	ft_bzero(logical_operator_node, sizeof(*logical_operator_node));
	logical_operator_node->type = (enum e_node_type)((*tok_lst)->type);
	logical_operator_node->content.child.left = *ast;
	*ast = logical_operator_node;
	eat_token(tok_lst);
	return (build_ast(tok_lst, &((*ast)->content.child.right)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/08 18:25:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse_parenthesis(t_token **tok_lst, t_node **ast)
{
	t_node	*sub_tree;

	eat_token(tok_lst);
	if (build_ast(tok_lst, &sub_tree) == FALSE)
	{
		return (FALSE);
	}
	if (*tok_lst != NULL && (*tok_lst)->type == Cparenth_tok)
	{
		if (*ast == NULL)
			*ast = sub_tree;
		else if (is_leaf((*tok_lst)->type == FALSE))
			(*ast)->content.child.right = sub_tree;
		eat_token(tok_lst);
		return (TRUE);
	}
	return (FALSE);
}

bool	parse_separator(t_token **tok_lst, t_node **ast)
{
	t_node	*separator_node;

	if (*ast == NULL)
		return (FALSE);
	separator_node = NULL;
	separator_node = gc_malloc(sizeof(*separator_node));
	ft_bzero(separator_node, sizeof(*separator_node));
	separator_node->type = (enum e_node_type)((*tok_lst)->type);
	separator_node->content.child.left = *ast;
	*ast = separator_node;
	eat_token(tok_lst);
	return (parse_simple_cmd(tok_lst, &((*ast)->content.child.right)));
}

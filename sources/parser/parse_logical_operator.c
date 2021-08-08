/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_logical_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 00:35:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse_logical_operator(t_token **tok_lst, t_node **ast)
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
	return (parse_pipeline(tok_lst, &((*ast)->content.child.right)));
}

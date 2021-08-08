/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/08 23:37:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse_parenthesis(t_token **tok_lst, t_node **ast)
{
	t_node	*sub_tree;
	static int		is_in_parenth = 0;

	if ((*tok_lst)->type == Oparenth_tok)
		++is_in_parenth;
	else if ((*tok_lst)->type == Cparenth_tok)
		--is_in_parenth;
	if (is_in_parenth < 0)
	{
		is_in_parenth = 0;
		return (FALSE);
	}
	eat_token(tok_lst);
	if (build_ast(tok_lst, &sub_tree) == FALSE)
		return (FALSE);
	if (*tok_lst == NULL) 
	{
		if (is_in_parenth != 0)
		{
			is_in_parenth = 0;
			return (FALSE);
		}
		if (*ast == NULL)
			*ast = sub_tree;
		is_in_parenth = 0;
		return (TRUE);
	}
	is_in_parenth = 0;
	return (FALSE);
}

bool	parse_pipeline(t_token **tok_lst, t_node **ast)
{
	t_node	*pipe_node;
	t_node	*simple_cmd;
	t_node	*pipeline;
	bool	ret;
	
	ret = TRUE;
	if ((*tok_lst)->type == Oparenth_tok)
		return (parse_parenthesis(tok_lst, ast));
	if (parse_simple_cmd(tok_lst, &simple_cmd) == FALSE)
		return (FALSE);
	pipeline = simple_cmd;
	while (*tok_lst != NULL && (*tok_lst)->type == Pipe_tok)
	{
		pipe_node = NULL;
		pipe_node = gc_malloc(sizeof(*pipe_node));
		ft_bzero(pipe_node, sizeof(*pipe_node));
		pipe_node->type = Pipe_node;
		eat_token(tok_lst);
		pipe_node->content.child.left = pipeline;
		pipeline = pipe_node;
		if (*tok_lst != NULL && is_parenthesis((*tok_lst)->type) == TRUE)
			ret = parse_parenthesis(tok_lst, &(pipeline->content.child.right));
		else
			ret = parse_simple_cmd(tok_lst, &(pipeline->content.child.right));
		if (ret == FALSE)
			break ;
	}
	*ast = pipeline;
	return (ret);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:31:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/14 19:43:50 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*get_before_matching_parenth(t_token *tok_lst)
{
	int		parenth_count;
	t_token	*previous;

	parenth_count = 1;
	previous = tok_lst;
	tok_lst = tok_lst->next;
	while (tok_lst != NULL)
	{
		if (tok_lst->type == Oparenth_tok)
			++parenth_count;
		else if (tok_lst->type == Cparenth_tok)
		{
			--parenth_count;
			if (parenth_count == 0)
				return (previous);
		}
		previous = tok_lst;
		tok_lst = tok_lst->next;
	}
	return (NULL);
}

static bool	check_errors_and_build_sub_tree(
		t_token **tok_lst, t_token **sub_tok_lst, t_node **sub_tree)
{
	if ((*tok_lst != NULL
			&& (is_leaf((*tok_lst)->type) == true
				|| (*tok_lst)->type == Oparenth_tok))
		|| build_ast(sub_tok_lst, sub_tree, true) == false)
	{
		clear_tokens(sub_tok_lst);
		return (false);
	}
	return (true);
}

static bool	eat_token_and_return_false(t_token **tok_lst)
{
	eat_token(tok_lst);
	return (false);
}

bool	parse_parenthesis(t_token **tok_lst, t_node **ast)
{
	t_token	*before_matching_parenth;
	t_node	*sub_tree;
	t_token	*sub_tok_lst;

	if ((*tok_lst)->next != NULL && (*tok_lst)->next->type == Cparenth_tok)
		return (eat_token_and_return_false(tok_lst));
	before_matching_parenth = get_before_matching_parenth(*tok_lst);
	eat_token(tok_lst);
	if (before_matching_parenth == NULL)
	{
		clear_tokens(tok_lst);
		return (print_error_and_return(*tok_lst));
	}
	sub_tok_lst = *tok_lst;
	*tok_lst = before_matching_parenth->next->next;
	gc_free((void **)&before_matching_parenth->next->data);
	gc_free((void **)&before_matching_parenth->next);
	if (check_errors_and_build_sub_tree(tok_lst, &sub_tok_lst, &sub_tree)
		== false)
		return (false);
	clear_tokens(&sub_tok_lst);
	*ast = sub_tree;
	if (*tok_lst != NULL && (*tok_lst)->type == Pipe_tok)
		return (false);
	return (true);
}

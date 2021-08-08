/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:31:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 00:31:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	reset_parenth_and_return(bool ret, int *is_in_parenth)
{
	*is_in_parenth = 0;
	return (ret);
}

bool	parse_parenthesis(t_token **tok_lst, t_node **ast)
{
	t_node			*sub_tree;
	static int		is_in_parenth = 0;

	if ((*tok_lst)->type == Oparenth_tok)
		++is_in_parenth;
	else if ((*tok_lst)->type == Cparenth_tok)
		--is_in_parenth;
	if (is_in_parenth < 0)
		return (reset_parenth_and_return(FALSE, &is_in_parenth));
	eat_token(tok_lst);
	if (build_ast(tok_lst, &sub_tree) == FALSE)
		return (FALSE);
	if (*tok_lst == NULL)
	{
		if (is_in_parenth != 0)
			return (reset_parenth_and_return(FALSE, &is_in_parenth));
		if (*ast == NULL)
			*ast = sub_tree;
		return (reset_parenth_and_return(TRUE, &is_in_parenth));
	}
	return (reset_parenth_and_return(TRUE, &is_in_parenth));
}

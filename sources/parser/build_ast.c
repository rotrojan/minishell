/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:59:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/04 22:12:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eat_token(t_token **tok_lst)
{
	t_token	*tmp;

	tmp = *tok_lst;
	if (*tok_lst == NULL)
		return ;
	*tok_lst = (*tok_lst)->next;
	gc_free(tmp->data);
	tmp->data = NULL;
	gc_free(tmp);
	tmp = NULL;
}

void	parse_parenthesis(t_token **tok_lst, int *in_parenth)
{
	if ((*tok_lst)->type == Oparenth_tok)
		++(*in_parenth);
	else if ((*tok_lst)->type == Cparenth_tok)
		--(*in_parenth);
	/* eat_token(tok_lst); */
}

bool	build_ast(t_token **tok_lst, t_node **ast)
{
	bool		ret;
	static int	in_parenth = 0;

	while (*tok_lst != NULL)
	{
		if ((*tok_lst)->type == Oparenth_tok
			|| (*tok_lst)->type == Cparenth_tok)
			parse_parenthesis(tok_lst, &in_parenth);
		else if (is_logical_operator((*tok_lst)->type) == TRUE)
			ret = parse_logical_operator(tok_lst, ast);
		else if (is_pipe((*tok_lst)->type) == TRUE)
			ret = parse_pipe(tok_lst, ast);
		else if (is_leaf((*tok_lst)->type) == TRUE)
			ret = parse_simple_cmd(tok_lst, ast);
		else if ((*tok_lst)->type == Amp_tok)
			return (FALSE);
		if (ret == FALSE || in_parenth < 0)
			return (FALSE);
	}
	if (in_parenth != 0)
		return (FALSE);
	return (TRUE);
}

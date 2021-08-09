/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:59:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 21:07:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This function is used by all the parsers during the building of the AST: it
** "eats" the next token, meaning freeing the first token of the tok_lst token
**list (using gc_free from the libgc) and setting the head of tok_lst to the
** next comming token.*/

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

/*
** Once the lexing phase is done, the token linked list is processed by the
** build_ast() function to build the AST Abstract Syntax Tree that will be
** finally executed in the shell loop.
** According to the token met in the token linked list, the proper parser is
** called untill the tok_lst token list is empty.
** On success, build_ast() return TRUE, otherwise, FALSE is returned.
*/

bool	build_ast(t_token **tok_lst, t_node **ast)
{
	bool		ret;

	while (*tok_lst != NULL)
	{
		if ((*tok_lst)->type == Oparenth_tok
			|| (*tok_lst)->type == Cparenth_tok)
			ret = parse_parenthesis(tok_lst, ast);
		else if (is_leaf((*tok_lst)->type) == FALSE)
			ret = parse_logical_operator(tok_lst, ast);
		else
			ret = parse_pipeline(tok_lst, ast);
		if (ret == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:31:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/30 05:00:24 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Called from the beginning of a simple command, the parse_parenthesis() will
** recursively call build_ast() and will check after it's execution if the 
** next encountered token is a closing parenthesis (that is why build_ast loops
** untill the end of the token linked list or untill a Cparenth_tok token is
** met.
*/

bool	parse_parenthesis(t_token **tok_lst, t_node **ast)
{
	eat_token(tok_lst);
	if (*tok_lst == NULL)
		return (print_error_and_return(*tok_lst));
	if ((*tok_lst)->type == Cparenth_tok)
		return (false);
	if (build_ast(tok_lst, ast) == false)
		return (false);
	if (*tok_lst == NULL || (*tok_lst)->type != Cparenth_tok)
		return (false);
	eat_token(tok_lst);
	if (*tok_lst != NULL
			&& (is_leaf((*tok_lst)->type) == true
			|| (*tok_lst)->type == Oparenth_tok))
		return (false);
	return (true);
}

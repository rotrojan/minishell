/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:11:18 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 21:03:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Returns TRUE if the token is a redirection. Otherwise, returns FALSE.
*/

bool	is_redirection(enum e_tok_type type)
{
	return (type == Lesser_tok || type == Dlesser_tok
		|| type == Greater_tok || type == Dgreater_tok);
}

/*
** Returns TRUE if the token is part of a simple command. Otherwise, returns
** FALSE.
*/

bool	is_leaf(enum e_tok_type type)
{
	return (is_redirection(type) == TRUE || type == Word_tok);
}

/*
** Returns TRUE if the token is a parenthesis. Otherwise, returns FALSE.
*/

bool	is_parenthesis(enum e_tok_type type)
{
	return (type == Oparenth_tok || type == Cparenth_tok);
}

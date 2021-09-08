/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:11:18 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/08 20:38:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Returns true if the token is a redirection. Otherwise, returns false.
*/

bool	is_redirection(enum e_tok_type type)
{
	return (type == Lesser_tok || type == Dlesser_tok
		|| type == Greater_tok || type == Dgreater_tok);
}

/*
** Returns true if the token is part of a simple command. Otherwise, returns
** false.
*/

bool	is_leaf(enum e_tok_type type)
{
	return (is_redirection(type) == true || type == Word_tok);
}

/*
** Returns true if the token is a parenthesis. Otherwise, returns false.
*/

bool	is_parenthesis(enum e_tok_type type)
{
	return (type == Oparenth_tok || type == Cparenth_tok);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:11:18 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/28 00:07:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirection(enum e_tok_type type)
{
	return (type == Lesser_tok || type == Dlesser_tok
		|| type == Greater_tok || type == Dgreater_tok);
}

bool	is_leaf(enum e_tok_type type)
{
	return (is_redirection(type) == TRUE || type == Word_tok);
}

bool	is_logical_operator(enum e_tok_type type)
{
	return (type == And_tok || type == Or_tok);
}

bool	is_pipe(enum e_tok_type type)
{
	return (type == Pipe_tok);
}

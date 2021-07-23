/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:11:18 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/23 18:35:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_redirection(enum e_tok_type type)
{
	return (type == Lesser_tok || type == Dlesser_tok
		|| type == Greater_tok || type == Dgreater_tok);
}

t_bool	is_leaf(enum e_tok_type type)
{
	return (is_redirection(type) == True || type == Word_tok);
}

t_bool	is_logical_operator(enum e_tok_type type)
{
	return (type == And_tok || type == Or_tok);
}

t_bool	is_pipe(enum e_tok_type type)
{
	return (type == Pipe_tok);
}

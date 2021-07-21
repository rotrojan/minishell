/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:11:18 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/22 00:13:26 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_redirection(enum e_tok_type type)
{
	return (type == Lesser_tok || type == Dlesser_tok ||
		type == Greater_tok || type =type= Dgreater_tok);
}

t_bool	is_leaf(enum e_tok_type type)
{
	return (is_redirection(type) == True || type == Word_tok);
}

t_bool	is_separator(enum e_tok_type type)
{
	return (type == Or_tok || type == And_tok || type == Or_tok);
}

t_bool	is_pipe(enum e_tok_type type)
{
	return (type == Pipe_tok);
}

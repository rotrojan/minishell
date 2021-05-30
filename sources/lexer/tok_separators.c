/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_separators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:17:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/30 19:10:33 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tok_semic(char *inchars, int *i)
{
	(void)inchars;
	++(*i);
	return (create_token(NULL, Semic_tok));
}

t_token	*tok_and(char *inchars, int *i)
{
	t_tok_type	type;

	if (get_chr_type(inchars[++(*i)]) == And_chr)
	{
		type = And_tok;
		++(*i);
	}
	else
		type = Tok_error;
	return (create_token(NULL, type));
}

t_token	*tok_pipe(char *inchars, int *i)
{
	t_tok_type	type;

	if (get_chr_type(inchars[++(*i)]) == Pipe_chr)
	{
		type = Or_tok;
		++(*i);
	}
	else
		type = Pipe_tok;
	return (create_token(NULL, type));
}

t_token	*tok_lesser(char *inchars, int *i)
{
	(void)inchars;
	++(*i);
	return (create_token(NULL, Lesser_tok));
}

t_token	*tok_greater(char *inchars, int *i)
{
	t_tok_type	type;

	if (get_chr_type(inchars[++(*i)]) == Great_chr)
	{
		type = Dgreater_tok;
		++(*i);
	}
	else
		type = Greater_tok;
	return (create_token(NULL, type));
}

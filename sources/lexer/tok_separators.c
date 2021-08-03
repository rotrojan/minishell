/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_separators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:17:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/03 19:34:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tok_parenth(char *inchars, int *i, t_error *error)
{
	char			*data;
	enum e_tok_type	type;

	(void)error;
	if (inchars[*i] == '(')
		type = Oparenth_tok;
	else
		type = Cparenth_tok;
	data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
	ft_strlcpy(data, &inchars[*i], SIZE_OF_ONE_CHAR_STR);
	++(*i);
	return (create_token(data, type));
}

t_token	*tok_semic(char *inchars, int *i, t_error *error)
{
	char	*data;

	(void)error;
	(void)inchars;
	data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
	ft_strlcpy(data, ";", SIZE_OF_ONE_CHAR_STR);
	++(*i);
	return (create_token(data, Semic_tok));
}

t_token	*tok_and(char *inchars, int *i, t_error *error)
{
	enum e_tok_type	type;
	char			*data;

	if (get_chr_type(inchars[++(*i)]) == And_chr)
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_TWO_CHAR_STR);
		ft_strlcpy(data, "&&", SIZE_OF_TWO_CHAR_STR);
		type = And_tok;
		++(*i);
	}
	else
	{
		*error = Amp_token;
		return (NULL);
	}
	return (create_token(data, type));
}

t_token	*tok_pipe(char *inchars, int *i, t_error *error)
{
	enum e_tok_type	type;
	char			*data;

	(void)error;
	if (get_chr_type(inchars[++(*i)]) == Pipe_chr)
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_TWO_CHAR_STR);
		ft_strlcpy(data, "||", SIZE_OF_TWO_CHAR_STR);
		type = Or_tok;
		++(*i);
	}
	else
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
		ft_strlcpy(data, "|", SIZE_OF_ONE_CHAR_STR);
		type = Pipe_tok;
	}
	return (create_token(data, type));
}

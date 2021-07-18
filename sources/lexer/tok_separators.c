/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_separators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:17:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/18 20:33:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SIZE_OF_ONE_CHAR_STR 2
#define SIZE_OF_TWO_CHAR_STR 3

t_token	*tok_semic(char *inchars, int *i)
{
	char	*data;

	(void)inchars;
	data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
	ft_strlcpy(data, ";", SIZE_OF_ONE_CHAR_STR);
	++(*i);
	return (create_token(data, Semic_tok));
}

t_token	*tok_and(char *inchars, int *i)
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
		data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
		ft_strlcpy(data, "&", SIZE_OF_ONE_CHAR_STR);
		type = Amp_tok;
	}
	return (create_token(data, type));
}

t_token	*tok_pipe(char *inchars, int *i)
{
	enum e_tok_type	type;
	char			*data;

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

t_token	*tok_lesser(char *inchars, int *i)
{
	char			*data;
	enum e_tok_type	type;

	if (get_chr_type(inchars[++(*i)]) == Less_chr)
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_TWO_CHAR_STR);
		ft_strlcpy(data, "<<", SIZE_OF_TWO_CHAR_STR);
		type = Dlesser_tok;
		++(*i);
	}
	else
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
		ft_strlcpy(data, "<", SIZE_OF_ONE_CHAR_STR);
		type = Lesser_tok;
	}
	return (create_token(data, type));
}

t_token	*tok_greater(char *inchars, int *i)
{
	char			*data;
	enum e_tok_type	type;

	if (get_chr_type(inchars[++(*i)]) == Great_chr)
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_TWO_CHAR_STR);
		ft_strlcpy(data, ">>", SIZE_OF_TWO_CHAR_STR);
		type = Dgreater_tok;
		++(*i);
	}
	else
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
		ft_strlcpy(data, ">", SIZE_OF_ONE_CHAR_STR);
		type = Greater_tok;
	}
	return (create_token(data, type));
}

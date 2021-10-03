/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_separators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:17:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/03 01:14:52 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Tokenize the Oparenth_tok and the Cparenth_tok tokens.
*/

t_token	*tok_parenth(char *inchars, int *i)
{
	char			*data;
	enum e_tok_type	type;

	if (inchars[*i] == '(')
		type = Oparenth_tok;
	else
		type = Cparenth_tok;
	data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
	ft_strlcpy(data, &inchars[*i], SIZE_OF_ONE_CHAR_STR);
	++(*i);
	return (create_token(data, type));
}

/*
** Tokenize the Semic_tok tokens.
*/

t_token	*tok_semic(char *inchars, int *i)
{
	char	*data;

	(void)inchars;
	data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
	ft_strlcpy(data, ";", SIZE_OF_ONE_CHAR_STR);
	++(*i);
	return (create_token(data, Semic_tok));
}

/*
** Tokenize the And_tok and the Amp_tok tokens. Since the Amp_tok token is not
** handled by minishell, if this token is found, NULL is returned and an error
** message is displayed.
*/

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
		ft_dprintf(STDERR_FILENO,
			"\nminishell: the `&' operator is not handled by minishell\n");
		return (NULL);
	}
	return (create_token(data, type));
}

/*
** Tokenize the Pipe_tok and the Or_tok tokens.
*/

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

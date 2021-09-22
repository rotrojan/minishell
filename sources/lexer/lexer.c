/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:09:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/22 04:28:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** The get_next_token() function call from a function pointer array the proper
** tokenizer depending on the type of the char encountered in the inchars string
** (see lexer.h for further informations).
*/

static t_token	*get_next_token(char *inchars, int *i)
{
	t_token	*(*tokenizer[NB_CHR_TYPE])(char*, int*);

	tokenizer[Null_chr] = NULL;
	tokenizer[Any_chr] = &tok_word;
	tokenizer[Space_chr] = NULL;
	tokenizer[Squote_chr] = &tok_word;
	tokenizer[Dquote_chr] = &tok_word;
	tokenizer[Less_chr] = &tok_lesser;
	tokenizer[Great_chr] = &tok_greater;
	tokenizer[And_chr] = &tok_and;
	tokenizer[Semic_chr] = &tok_semic;
	tokenizer[Pipe_chr] = &tok_pipe;
	tokenizer[Oparenth_chr] = &tok_parenth;
	tokenizer[Cparenth_chr] = &tok_parenth;
	return (tokenizer[get_chr_type(inchars[*i])](inchars, i));
}

/*
** Called from the shell loop, build_tok_lst() will build the tokens chained
** linked list fron the inchars string returned by the input functions. First,
** all the white spaces are skipped. Then, until the inchars string is fully
** scanned, the following operations are performed in a loop:
** - get_next_token() returns the next token;
** - this token is added to the linked list by add_token();
** - the next white spaces are skipped.
** The lexer() function returns true on succes. Otherwise, false is returned and
** the error variable is set accordingly by get_next_token().
*/

bool	build_tok_lst(char *inchars, t_token **tok_lst)
{
	int		i;
	t_token	*new_tok;

	i = 0;
	while (ft_isspace(inchars[i]))
		++i;
	while (inchars[i])
	{
		new_tok = get_next_token(inchars, &i);
		if (new_tok == NULL)
			return (false);
		add_token(new_tok, tok_lst);
		while (ft_isspace(inchars[i]))
			++i;
	}
	return (true);
}

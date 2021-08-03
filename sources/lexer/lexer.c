/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:09:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/03 19:31:57 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_next_token(char *inchars, int *i, t_error *error)
{
	t_token	*(*tokenizer[NB_CHR_TYPE])(char*, int*, t_error*);

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
	return (tokenizer[get_chr_type(inchars[*i])](inchars, i, error));
}

bool	build_tok_lst(char *inchars, t_token **tok_lst, t_error *error)
{
	int		i;
	t_token	*new_tok;

	i = 0;
	while (inchars[i])
	{
		while (ft_isspace(inchars[i]))
			++i;
		new_tok = get_next_token(inchars, &i, error);
		if (*error != No_error)
			return (FALSE);
		add_token(new_tok, tok_lst);
	}
	return (TRUE);
}

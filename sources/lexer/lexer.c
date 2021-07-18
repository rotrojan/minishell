/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:09:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/18 20:21:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_next_token(char *inchars, int *i)
{
	static	t_token *(*tokenizer[])(char*, int*) = {
		[Error_chr] = &tok_word,
		[Alpha_chr] = &tok_word,
		[Digit_chr] = &tok_word,
		[Print_chr] = &tok_word,
		[Space_chr] = NULL,
		[Squote_chr] = &tok_word,
		[Dquote_chr] = &tok_word,
		[Dol_chr] = &tok_word,
		[Less_chr] = &tok_lesser,
		[Great_chr] = &tok_greater,
		[And_chr] = &tok_and,
		[Esc_chr] = &tok_word,
		[Semic_chr] = &tok_semic,
		[Pipe_chr] = &tok_pipe
	};

	if (get_chr_type(inchars[*i]) == Error_chr)
		return (NULL);
	return ((tokenizer[get_chr_type(inchars[*i])])(inchars, i));
}

void	build_tok_lst(char *inchars, t_token **tok_lst)
{
	int		i;
	t_token	*new_tok;

	i = 0;
	while (inchars[i])
	{
		while (ft_isspace(inchars[i]))
			++i;
		new_tok = get_next_token(inchars, &i);
		add_token(new_tok, tok_lst);
	}
}

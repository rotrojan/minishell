/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:39:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/04 19:53:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static enum e_chr_rules	word_rules(enum e_chr_type chr_type)
{
	enum e_chr_rules const	word_rules[] = {
		[Null_chr] = Not_accepted,
		[Any_chr] = Accepted,
		[Space_chr] = Not_accepted,
		[Squote_chr] = Accepted,
		[Dquote_chr] = Accepted,
		[Less_chr] = Not_accepted,
		[Great_chr] = Not_accepted,
		[And_chr] = Not_accepted,
		[Semic_chr] = Not_accepted,
		[Pipe_chr] = Not_accepted,
		[Oparenth_chr] = Not_accepted,
		[Cparenth_chr] = Not_accepted
	};

	return (word_rules[chr_type]);
}

static enum e_chr_rules	is_valid(
	char c, bool *is_in_squotes, bool *is_in_dquotes, t_error *error)
{
	enum e_chr_type	chr_type;

	chr_type = get_chr_type(c);
	if (*is_in_squotes == FALSE && *is_in_dquotes == FALSE)
	{
		if (chr_type == Squote_chr)
			*is_in_squotes = TRUE;
		else if (chr_type == Dquote_chr)
			*is_in_dquotes = TRUE;
	}
	else
	{
		if (chr_type == Null_chr)
		{
			*error = Unexpected_eof;
			return (Not_accepted);
		}
		if (chr_type == Squote_chr && *is_in_squotes == TRUE)
			*is_in_squotes = FALSE;
		else if (chr_type == Dquote_chr && *is_in_dquotes == TRUE)
			*is_in_dquotes = FALSE;
		return (Accepted);
	}
	return (word_rules(chr_type));
}

t_token	*tok_word(char *inchars, int *i, t_error *error)
{
	char				*data;
	int					j;
	bool				is_in_squotes;
	bool				is_in_dquotes;

	j = 0;
	is_in_squotes = FALSE;
	is_in_dquotes = FALSE;
	data = gc_malloc(sizeof(*data) * 1);
	*data = '\0';
	while (is_valid(inchars[*i + j], &is_in_squotes, &is_in_dquotes, error)
		== Accepted)
		++j;
	if (*error != No_error)
	{
		gc_free(data);
		return (NULL);
	}
	data = join_chars(data, inchars + *i, j);
	*i += j;
	return (create_token(data, Word_tok));
}

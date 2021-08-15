/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:39:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/15 18:39:43 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** List the rules of acceptance of a character in a word token without taking in
** account the presence of quotes (which will be verified by the is_valid()
** function.
*/

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

/*
** Check for the validity of the characters in inchars with the word_rules()
** function according to the quoting state (between two single quotes or two
** double quotes, all the characters are accepted). If the end of the inchars
** string is reached and one of the quote state is still equal to TRUE, error is
** set to Unexpected_eof and FALSE is returned. Otherwise, TRUE is returned.
*/

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

/*
** Starting from the beginning of the token in the inchars string, the validity
** of the characters is checked by the is_valid() function. If the character is
** not valid, the end of the token is reached and ft_strndup() will add the word
** identifier to the data field of the token link.
** The states is_in_squotes and is_in_dquotes are declared here but are modified
** in is_valid() because these states must be persistent from one call to
** is_valid() to an other.
*/

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
	data = ft_strndup(inchars + *i, j);
	*i += j;
	return (create_token(data, Word_tok));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:39:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/23 01:15:49 by rotrojan         ###   ########.fr       */
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
** string is reached and one of the quote state is still equal to true, error is
** set to Unexpected_eof and false is returned. Otherwise, true is returned.
*/

static enum e_chr_rules	is_valid(
	char c, bool *is_in_squotes, bool *is_in_dquotes)
{
	enum e_chr_type	chr_type;

	chr_type = get_chr_type(c);
	if (*is_in_squotes == false && *is_in_dquotes == false)
	{
		if (chr_type == Squote_chr)
			*is_in_squotes = true;
		else if (chr_type == Dquote_chr)
			*is_in_dquotes = true;
	}
	else
	{
		if (chr_type == Null_chr)
			return (Not_accepted);
		if (chr_type == Squote_chr && *is_in_squotes == true)
			*is_in_squotes = false;
		else if (chr_type == Dquote_chr && *is_in_dquotes == true)
			*is_in_dquotes = false;
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
static int	get_nb_escaped_quotes(char *str)
{
	int		nb_escaped_quotes;
	bool	in_squotes;
	bool	in_dquotes;

	nb_escaped_quotes = 0;
	in_squotes = false;
	in_dquotes = false;
	while (*str != '\0')
	{
		if (*str == '\'' && in_dquotes == false)
			in_squotes = (in_squotes == false);
		else if (*str == '"' && in_squotes == false)
			in_dquotes = (in_dquotes == false);
		else if ((in_dquotes == true && *str == '\'')
			|| (in_squotes == true && *str == '"'))
			++nb_escaped_quotes;
		++str;
	}
	return (nb_escaped_quotes);
}

static void	fill_with_escaped_quotes(
			char *str, char *tmp, bool *in_squotes, bool *in_dquotes)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && *in_dquotes == false)
			*in_squotes = (*in_squotes == false);
		else if (str[i] == '"' && *in_squotes == false)
			*in_dquotes = (*in_dquotes == false);
		else if ((*in_dquotes == true && str[i] == '\'')
			|| (*in_squotes == true && str[i] == '"'))
		{
			tmp[j++] = '\\';
			tmp[j++] = str[i];
		}
		else
			tmp[j++] = str[i];
		++i;
	}
}

void	escape_quoted_quotes(char **str)
{
	int		len;
	bool	in_squotes;
	bool	in_dquotes;
	char	*tmp;

	if (ft_strchr(*str, '"') != NULL
		|| ft_strchr(*str, '\'') != NULL)
	{
		len = get_len_with_escaped_quotes(*str);
		tmp = gc_malloc(sizeof(*tmp)
			* ((ft_strlen(*str) + get_nb_escaped_quotes(*str) + 1)));
		fill_with_escaped_quotes(*str, tmp, &in_squotes, &in_dquotes);
		gc_free((void **)str);
		*str = tmp;
	}
}

t_token	*tok_word(char *inchars, int *i)
{
	char	*data;
	int		j;
	bool	is_in_squotes;
	bool	is_in_dquotes;

	j = 0;
	is_in_squotes = false;
	is_in_dquotes = false;
	data = gc_malloc(sizeof(*data) * 1);
	*data = '\0';
	while (is_valid(inchars[*i + j], &is_in_squotes, &is_in_dquotes)
		== Accepted)
		++j;
	if (inchars[*i + j] == '\0'\
		&& (is_in_squotes == true || is_in_dquotes == true))
	{
		ft_dprintf(STDERR_FILENO,
			"\nminishell: syntax error: unexpected end of file");
		gc_free((void **)&data);
		return (NULL);
	}
	data = ft_strndup(inchars + *i, j);
	escape_quoted_quotes(&data);
	*i += j;
	return (create_token(data, Word_tok));
}

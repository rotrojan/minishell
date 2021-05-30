/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:39:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/30 19:45:29 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	word_rules(char c)
{
	static int	word_rules[] = {
		[Error_chr] = 0,
		[Alpha_chr] = 1,
		[Digit_chr] = 1,
		[Print_chr] = 1,
		[Space_chr] = 0,
		[Squote_chr] = 2,
		[Dquote_chr] = 2,
		[Dol_chr] = 2,
		[Less_chr] = 0,
		[Great_chr] = 0,
		[And_chr] = 0,
		[Esc_chr] = 2,
		[Semic_chr] = 0,
		[Pipe_chr] = 0
	};

	return (word_rules[get_chr_type(c)]);
}

static char	*str_quote(const char *inchars, int *i)
{
	int				j;
	char			*str;
	static	char	*(*quote_func[])(const char*, int*) = {
		[0] = &squote_func,
		[1] = &dquote_func,
		[2] = &escape_func,
		/* [3] = $dollar_func */
	};
	static char		quotes[] = {
		[0] = '\'',
		[1] = '\"',
		[2] = '\\',
		[3] = '$',
	};

	j = 0;
	while (j < NB_QUOTE_CHR)
	{
		if (inchars[*i] == quotes[j])
			str = quote_func[j](inchars, i);
		j++;
	}
	return (str);
}

static void	get_quote(const char *inchars, int *i, char **data, int *j)
{
	char	*quote;
	int		is_escaped;

	is_escaped = 0;
	if (inchars[*i] == '\\')
		is_escaped = 1;
	*data = join_chars(*data, inchars + *i, *j);
	*i += *j;
	*j = 0;
	quote = str_quote(inchars, i);
	if (is_escaped == 1)
		*data = join_chars(*data, quote, 1);
	else
		*data = join_chars(*data, quote, ft_strlen(quote));
	gc_free(quote);
}

t_token	*tok_word(char *inchars, int *i)
{
	char	*data;
	int		j;
	int		ret;

	j = 0;
	ret = word_rules(inchars[*i]);
	data = gc_malloc(sizeof(*data) * 1);
	*data = '\0';
	ret = word_rules(inchars[*i]);
	while (ret != 0)
	{
		if (ret == 2)
			get_quote(inchars, i, &data, &j);
		else
			++j;
		ret = word_rules(inchars[*i + j]);
	}
	data = join_chars(data, inchars + *i, j);
	*i += j;
	return (create_token(data, Word_tok));
}

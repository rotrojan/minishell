/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/08 20:38:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*escape_func(char *data)
{
	char					*c;
	int						j;
	static t_escaped_chrs	escaped_chr[NB_ESCAPED_CHR] = {
		{.chr = 't', .escaped_chr = '\t'}, {.chr = 'n', .escaped_chr = '\n'},
		{.chr = 'v', .escaped_chr = '\v'}, {.chr = 'f', .escaped_chr = '\f'},
		{.chr = 'r', .escaped_chr = '\r'}, {.chr = '0', .escaped_chr = '\0'}};

	j = 0;
	++(*i);
	c = NULL;
	c = gc_malloc(sizeof(*c) * 2);
	c[1] = '\0';
	while (j < NB_ESCAPED_CHR)
	{
		if (escaped_chr[j].chr == inchars[*i])
		{
			*c = escaped_chr[j].escaped_chr;
			break ;
		}
		++j;
	}
	if (j == NB_ESCAPED_CHR)
		*c = inchars[*i];
	++(*i);
	return (c);
}

static unsigned int	get_len_inside_dquotes(char const *data, int *i)
{
	unsigned int	len;
	unsigned int	*len_expanded_var;

	len = 0;
	++(*i);
	while (data[*i] != '"')
	{
		if ()
		++(*i);
	}
	++(*i);
	return (len);
}

static unsigned int	get_len_inside_squotes(char const *data, int *i)
{
	unsigned int	len;

	len = 0;
	++(*i);
	while (data[*i + len] != ''')
		++len;
	(*i) += len + 1;
	return (len);
}

static unsigned int	get_len_expanded_str(char const *str_to_expand)
{
	unsigned int	i;
	unsigned int	len;
	bool			is_in_dquotes;

	i = 0;
	len = 0;
	is_in_dquotes = false;
	while (str_to_expand[i] != NULL)
	{
		if (str_to_expand[i] != '"')
			is_in_dquotes == true;
		if (str_to_expand[i] != '''
			&& str_to_expand != '"'
			&& str_to_expand !='$')
			++len;
		else if (str_to_expand[i] == $)
			len += ft_strlen(ft_getenv);
	}
}

char	*squote_func(char *data)
{
	int		i;
	char	*expanded_str;

	while (inchars[*i + j] != '\'')
		++j;
	str = gc_malloc(sizeof(*str) * (j + 1));
	ft_strlcpy(str, inchars + *i, j + 1);
	(*i) += ++j;
	return (str);
}

char	*dquote_func(const char *inchars)
{
	int		j;
	char	*str;
	/* char	*tmp; */

	j = 0;
	str = NULL;
	++(*i);
	while (inchars[*i + j] != '\"')
	{
		/* if (inchars[*i + j] == '$') */
			/* tmp = dollar_func(inchars, i); */
		/* else if (inchars[*i + j] == '$') */
			/* tmp = escape_func(inchars, i); */
		++j;
	}
	str = gc_malloc(sizeof(*str) * (j + 1));
	ft_strlcpy(str, inchars + *i, j + 1);
	(*i) += ++j;
	return (str);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/30 19:47:00 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*escape_func(const char *inchars, int *i)
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

char	*squote_func(const char *inchars, int *i)
{
	int		j;
	char	*str;

	j = 0;
	str = NULL;
	++(*i);
	while (inchars[*i + j] != '\'')
		++j;
	str = gc_malloc(sizeof(*str) * (j + 1));
	ft_strlcpy(str, inchars + *i, j + 1);
	(*i) += ++j;
	return (str);
}

char	*dquote_func(const char *inchars, int *i)
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

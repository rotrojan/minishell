/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/10 22:00:56 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* char	*escape_func(char *data) */
/* { */
	/* char					*c; */
	/* int						j; */
	/* static t_escaped_chrs	escaped_chr[NB_ESCAPED_CHR] = { */
		/* {.chr = 't', .escaped_chr = '\t'}, {.chr = 'n', .escaped_chr = '\n'}, */
		/* {.chr = 'v', .escaped_chr = '\v'}, {.chr = 'f', .escaped_chr = '\f'}, */
		/* {.chr = 'r', .escaped_chr = '\r'}, {.chr = '0', .escaped_chr = '\0'}}; */

	/* j = 0; */
	/* ++(*i); */
	/* c = NULL; */
	/* c = gc_malloc(sizeof(*c) * 2); */
	/* c[1] = '\0'; */
	/* while (j < NB_ESCAPED_CHR) */
	/* { */
		/* if (escaped_chr[j].chr == inchars[*i]) */
		/* { */
			/* *c = escaped_chr[j].escaped_chr; */
			/* break ; */
		/* } */
		/* ++j; */
	/* } */
	/* if (j == NB_ESCAPED_CHR) */
		/* *c = inchars[*i]; */
	/* ++(*i); */
	/* return (c); */
/* } */

static int	get_len_without_quotes(char *str)
{
	bool	in_squotes;
	bool	in_dquotes;
	int		i;
	int		len;

	in_squotes = false;
	in_dquotes = false;
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (in_dquotes == false && str[i] == '\'')
			in_squotes = (in_squotes == false);
		else if (in_squotes == false && str[i] == '"')
			in_dquotes = (in_dquotes == false);
		else
			++len;
		++i;
	}
	return (len);
}

char	*remove_quotes(char *str)
{
	bool	in_squotes;
	bool	in_dquotes;
	int		i;
	int		j;
	char	*without_quotes;

	in_squotes = false;
	in_dquotes = false;
	i = 0;
	j = 0;
	without_quotes = gc_malloc(sizeof(*without_quotes)
			* (get_len_without_quotes(str) + 1));
	while (str[i] != '\0')
	{
		if (in_dquotes == false && str[i] == '\'')
			in_squotes = (in_squotes == false);
		else if (in_squotes == false && str[i] == '"')
			in_dquotes = (in_dquotes == false);
		else
			without_quotes[j++] = str[i];
		++i;
	}
	return (without_quotes);
}

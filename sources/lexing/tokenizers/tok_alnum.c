/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_alnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:27:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/21 19:47:05 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

static int	is_not_sep(char c)
{
	if (ft_isspace(c) || c == '<' || c == '>' || c == '|' || c == ';'
		|| c == '$' || c == '\'' || c == '\"' || c == '\0')
		return (0);
	return (1);
}

t_token	*tok_alnum(t_token **tok_lst, char *inchars, int *i, t_state state)
{
	t_token	*tok;
	char	*data;
	int		j;

	(void)inchars;
	j = *i;
	data = NULL;
	tok = NULL;
	if (state == State_general)
		while (is_not_sep(inchars[*i]))
			j++;
	if (state == State_insquote)
		while (inchars[j] != '\'')
			j++;
	if (state == State_indquote)
		while (inchars[j] != '\'')
			j++;
	data = gc_malloc(sizeof *data * (j - *i + 1));
	ft_strlcpy(data, &inchars[*i], j -*i);
	create_token(data, Alnum, tok_lst);
	return (tok);
}

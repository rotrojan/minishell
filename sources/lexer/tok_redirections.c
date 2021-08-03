/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:59:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/03 19:57:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tok_lesser(char *inchars, int *i, t_error *error)
{
	char			*data;
	enum e_tok_type	type;

	(void)error;
	if (get_chr_type(inchars[++(*i)]) == Less_chr)
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_TWO_CHAR_STR);
		ft_strlcpy(data, "<<", SIZE_OF_TWO_CHAR_STR);
		type = Dlesser_tok;
		++(*i);
	}
	else
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
		ft_strlcpy(data, "<", SIZE_OF_ONE_CHAR_STR);
		type = Lesser_tok;
	}
	return (create_token(data, type));
}

t_token	*tok_greater(char *inchars, int *i, t_error *error)
{
	char			*data;
	enum e_tok_type	type;

	(void)error;
	if (get_chr_type(inchars[++(*i)]) == Great_chr)
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_TWO_CHAR_STR);
		ft_strlcpy(data, ">>", SIZE_OF_TWO_CHAR_STR);
		type = Dgreater_tok;
		++(*i);
	}
	else
	{
		data = gc_malloc(sizeof(*data) * SIZE_OF_ONE_CHAR_STR);
		ft_strlcpy(data, ">", SIZE_OF_ONE_CHAR_STR);
		type = Greater_tok;
	}
	return (create_token(data, type));
}

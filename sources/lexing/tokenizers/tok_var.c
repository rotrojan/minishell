/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:27:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/25 14:35:30 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

char *expand_var(char *inchars, int *i, t_state *state)
{
	char	*str;
	int		j;

	j = 0;
	while ()

}

t_token	*tok_var(t_token **tok_lst, char *inchars, int *i, t_state *state)
{
	t_token	*tok;
	char	*data;
	int		j;

	j = 0;
	data = NULL;
	tok = NULL;
	if (*state == State_general)
		while (!is_sep(inchars[*i + j]))
			j++;
	else if (*state == State_indquote)
	{
		while (!is_sep(inchars[*i + j]))
		{
			if (inchars[*i + j] == '$')
			j++;
		}
		
	}
	data = gc_malloc(sizeof(*data) * (j + 1));
	ft_strlcpy(data, &inchars[*i], j + 1);
	create_token(data, Alnum, tok_lst);
	*i++ += j;
	return (tok);
}

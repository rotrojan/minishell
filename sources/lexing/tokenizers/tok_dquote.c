/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_dquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:07:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/25 12:38:06 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_token	*tok_dquote(t_token **tok_lst, char *inchars, int *i, t_state *state)
{
	t_token	*tok;
	char	*data;
	int		j;

	(void)state;
	printf("ok\n");
	j = 0;
	data = NULL;
	tok = NULL;
	while (inchars[*i + j] != '\'')
		j++;
	data = gc_malloc(sizeof(*data) * (j + 1));
	ft_strlcpy(data, &inchars[*i], j + 1);
	create_token(data, Alnum, tok_lst);
	*i++ += ++j;
	return (tok);
}

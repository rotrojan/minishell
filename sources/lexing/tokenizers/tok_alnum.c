/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_alnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:27:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/25 15:23:26 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tok_alnum(t_token **tok_lst, char *inchars, int *i, t_state *state)
{
	t_token	*tok;
	char	*data;
	int		j;

	(void)state;
	j = 0;
	data = NULL;
	tok = NULL;
	while (!is_sep(inchars[*i + j]))
		j++;
	data = gc_malloc(sizeof(*data) * (j + 1));
	ft_strlcpy(data, &inchars[*i], j + 1);
	tok = create_token(data, Alnum, tok_lst);
	*i++ += j;
	return (tok);
}

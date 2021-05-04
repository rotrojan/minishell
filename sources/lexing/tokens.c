/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:53:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/04 14:36:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(int value)
{
	t_token	*token;

	token = w_alloc(1, sizeof(token));
	if (token == NULL)
		return (NULL);
	token->value = value;
	token->next = NULL;
	token->prev = NULL;
	token->type = -1;
	return (token);
}

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		ft_putchar(tmp->value);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

t_token	*insert_token(t_token **tokens, t_cursor cursor, int value)
{
	t_token	*tmp;
	t_token	*new;

	tmp = *tokens;
	new = create_token(value);
	if (new == NULL)
		return (NULL);
	if (tmp == NULL)
		*tokens = new;
	else
	{
		while (tmp != cursor.on_token && tmp->next != NULL)
			tmp = tmp->next;
		if (cursor.on_token == NULL)
			tmp->next = new;
		else
		{
			new->prev = tmp->prev;
			tmp->prev = new;
			new->next = tmp;
		}
	}
	return (new);
}

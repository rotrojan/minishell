/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:53:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/11 17:48:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(int value)
{
	t_token	*token;

	token = gc_alloc(sizeof(t_token) * 1);
	token->value = value;
	token->next = NULL;
	token->prev = NULL;
	token->type = -1;
	return (token);
}

void	print_tokens(t_token *tokens)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = tokens;
	while (tmp->next != NULL)
	{
		ft_putchar(tmp->value);
		tmp = tmp->next;
		i++;
	}
}

void	clear_tokens(t_token **tokens)
{
	t_token	*tmp;
	t_token	*prev;

	tmp = *tokens;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		gc_free(prev);
	}
	*tokens = NULL;
}

void	insert_token(t_token **tokens, t_cursor *cursor, int value)
{
	t_token	*tmp;
	t_token	*new;

	new = create_token(value);
	new->prev = cursor->on_token->prev;
	if (cursor->on_token->prev != NULL)
		cursor->on_token->prev->next = new;
	new->next = cursor->on_token;
	cursor->on_token->prev = new;
	cursor->pos.y++;
	tmp = new;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	*tokens = tmp;
}

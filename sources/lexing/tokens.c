/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:53:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/03 21:03:01 by lucocozz         ###   ########.fr       */
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

char	*token_to_str(t_token **tokens)
{
	int		i;
	int		size;
	char	*str;
	t_token	*tmp;

	i = 0;
	size = 0;
	tmp = *tokens;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	str = w_alloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	tmp = *tokens;
	while (tmp)
	{
		str[i++] = tmp->value;
		tmp = tmp->next;
	}
	str[i] = '\0';
	return (str);
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

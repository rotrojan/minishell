/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 04:54:43 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/13 05:04:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	tokens_len(t_token *tokens)
{
	int		size;
	t_token	*tmp;

	size = 0;
	tmp = tokens;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_token	*tokens_head(t_cursor *cursor)
{
	t_token	*head;

	head = cursor->on_token;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}

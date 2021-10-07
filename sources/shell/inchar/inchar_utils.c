/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inchar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 04:54:43 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/03 03:36:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Self explanatory. */
void	print_inchars(t_inchar *inchars)
{
	int			i;
	t_inchar	*tmp;

	i = 0;
	tmp = inchars;
	while (tmp->next != NULL)
	{
		ft_putchar_err(tmp->value);
		tmp = tmp->next;
		i++;
	}
}

/* Return size of input line. */
int	inchars_len(t_cursor *cursor)
{
	int			size;
	t_inchar	*tmp;

	size = 0;
	tmp = inchars_head(cursor);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

/* Return start address of input line. */
t_inchar	*inchars_head(t_cursor *cursor)
{
	t_inchar	*head;

	head = cursor->on_inchar;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}

/* Return end address of input line. */
t_inchar	*inchars_queue(t_cursor *cursor)
{
	t_inchar	*queue;

	queue = cursor->on_inchar;
	while (queue->next != NULL)
		queue = queue->next;
	return (queue);
}

/* Add char at end of input line. */
void	push_back_inchars(t_inchar **inchars, int value)
{
	t_inchar	*new;
	t_inchar	*tmp;

	tmp = *inchars;
	if (!tmp)
		*inchars = create_inchar(value);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		new = create_inchar(value);
		tmp->next = new;
		new->prev = tmp;
	}
}

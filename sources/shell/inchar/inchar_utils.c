/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inchar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 04:54:43 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/16 15:15:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_inchars(t_inchar *inchars)
{
	int			i;
	t_inchar	*tmp;

	i = 0;
	tmp = inchars;
	while (tmp->next != NULL)
	{
		ft_putchar(tmp->value);
		tmp = tmp->next;
		i++;
	}
}

int	inchars_len(t_inchar *inchars)
{
	int			size;
	t_inchar	*tmp;

	size = 0;
	tmp = inchars;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_inchar	*inchars_head(t_cursor *cursor)
{
	t_inchar	*head;

	head = cursor->on_inchar;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}

char	*inchars_to_line(t_inchar **inchars)
{
	int			i;
	int			size;
	char		*line;
	t_inchar	*tmp;

	i = 0;
	tmp = *inchars;
	size = inchars_len(tmp);
	line = gc_alloc(sizeof(char) * (size + 1));
	while (tmp->next != NULL)
	{
		line[i++] = tmp->value;
		tmp = tmp->next;
	}
	line[i] = '\0';
	clear_inchars(inchars);
	return (line);
}

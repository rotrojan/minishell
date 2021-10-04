/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:53:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/03 03:41:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Self explanatory. */
t_inchar	*create_inchar(int value)
{
	t_inchar	*inchar;

	inchar = gc_malloc(sizeof(t_inchar) * 1);
	inchar->value = value;
	inchar->next = NULL;
	inchar->prev = NULL;
	return (inchar);
}

/* Self explanatory. */
void	free_inchars(t_cursor *cursor)
{
	t_inchar	*prev;
	t_inchar	*inchars;

	inchars = inchars_head(cursor);
	while (inchars)
	{
		prev = inchars;
		inchars = inchars->next;
		gc_free((void **)&prev);
	}
}

/* Convert string to inchar list. */
char	*inchars_to_line(t_cursor *cursor)
{
	int			i;
	int			size;
	char		*line;
	t_inchar	*tmp;

	i = 0;
	tmp = inchars_head(cursor);
	if (tmp->value == EOL)
		return (NULL);
	size = inchars_len(cursor);
	line = gc_malloc(sizeof(char) * (size + 1));
	while (tmp->next != NULL)
	{
		line[i++] = tmp->value;
		tmp = tmp->next;
	}
	line[i] = '\0';
	return (line);
}

/* Convert inchar list to string. */
t_inchar	*line_to_inchars(char *line)
{
	int			i;
	t_inchar	*inchars;

	i = 0;
	inchars = NULL;
	if (line == NULL)
		return (create_inchar(EOL));
	push_back_inchars(&inchars, line[i++]);
	while (line[i])
		push_back_inchars(&inchars, line[i++]);
	push_back_inchars(&inchars, EOL);
	return (inchars);
}

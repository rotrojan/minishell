/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:56:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 18:17:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Self explanatory. */
t_history	*create_history(char *line)
{
	t_history	*history;

	history = gc_alloc(sizeof(t_history) * 1);
	history->line = line;
	history->next = NULL;
	history->prev = NULL;
	return (history);
}

/* Self explanatory. */
void	free_history(void)
{
	t_history		*tmp;
	t_history		*prev;
	t_history_data	*history;

	history = get_history();
	tmp = history->data;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		gc_free(prev);
	}
	history->data = NULL;
	history->tmp_nav = NULL;
	gc_free(history->input);
}

/* Self explanatory. */
void	push_front_history(t_history **history, char *line)
{
	t_history	*new;
	t_history	*tmp;

	tmp = *history;
	new = create_history(line);
	if (tmp != NULL)
	{
		new->next = tmp;
		tmp->prev = new;
	}
	*history = new;
}

/* Read HISTORY_PATH and save it in accessible memory. */
t_history_data	*init_history(void)
{
	int				fd;
	char			*line;
	t_history_data	*history;

	line = NULL;
	history = get_history();
	history->data = NULL;
	history->input = ft_strdup("");
	fd = open(HISTORY_PATH, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (line[0] != '\0')
				push_front_history(&history->data, line);
			else
				gc_free(line);
		}
		close(fd);
		history->tmp_nav = NULL;
	}
	return (history);
}

/* Self explanatory. */
void	display_history(t_cursor *cursor, char *line)
{
	char		*goto_cap;
	t_inchar	*tmp;

	tmp = cursor->on_inchar;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		cursor_move_left(cursor);
	}
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar);
	ft_putxchar(' ', inchars_len(tmp));
	tputs(goto_cap, 1, ft_putchar);
	cursor->on_inchar = line_to_inchars(line);
	print_inchars(cursor->on_inchar);
	while (cursor->on_inchar->next != NULL)
	{
		cursor->on_inchar = cursor->on_inchar->next;
		cursor_move_right(cursor);
	}
}

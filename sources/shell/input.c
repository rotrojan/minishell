/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/27 23:59:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	control_key(t_cursor *cursor, int c)
{
	int					i;
	static const t_key	keys[] = {{BACKSPACE, &backspace_key},
	{DELETE, &delete_key}, {KEY_LEFT, &left_arrow_key}, {KEY_END, &end_key},
	{KEY_RIGHT, &right_arrow_key}, {KEY_HOME, &home_key},
	{CTRL_L, &ctrl_l_key}, {KEY_UP, &history_get_up},
	{KEY_DOWN, &history_get_down}};

	i = 0;
	if (c == CTRL_D)
		exit_shell(EXIT_SUCCESS, "\n");
	while (i < NB_KEY)
	{
		if (c == keys[i].key)
			keys[i].function(cursor);
		i++;
	}
}

static char	*get_line(t_cursor *cursor)
{
	char	*line;

	if (errno == EINTR)
	{
		errno = 0;
		handle_signals();
		line = ft_strdup("");
	}
	else
		line = inchars_to_line(inchars_head(cursor));
	free_inchars(inchars_head(cursor));
	return (line);
}

/* Read and return input line for shell. */
char	*input(void)
{
	int			c;
	t_cursor	cursor;

	cursor.on_inchar = create_inchar(EOL);
	cursor.pos = get_cursor_pos();
	while (1)
	{
		if (errno == EINTR)
			return (get_line(&cursor));
		c = ft_getch();
		if (c != ERR)
		{
			if (c == '\n')
				return (get_line(&cursor));
			else if (!ft_iscntrl(c))
				insert_inchar(&cursor, c);
			else
				control_key(&cursor, c);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/20 16:05:21 by lucocozz         ###   ########.fr       */
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

/* Read and return input line for shell. */
char	*input(void)
{
	int			c;
	char		*line;
	t_cursor	cursor;

	cursor.on_inchar = create_inchar(EOL);
	cursor.pos = get_cursor_pos();
	while (1)
	{
		c = ft_getch();
		if (c != ERR)
		{
			if (c == '\n')
			{
				line = inchars_to_line(inchars_head(&cursor));
				return (line);
			}
			else if (!ft_iscntrl(c))
				insert_inchar(&cursor, c);
			else
				control_key(&cursor, c);
		}
	}
}

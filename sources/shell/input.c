/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/13 05:04:46 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	control_key(t_cursor *cursor, int c)
{
	if (c == CTRL_D)
		exit_shell(EXIT_SUCCESS, "\n");
	else if (c == BACKSPACE)
		backspace_key(cursor);
	else if (c == KEY_LEFT)
		left_arrow_key(cursor);
	else if (c == KEY_RIGHT)
		right_arrow_key(cursor);
	else if (c == DELETE)
		delete_key(cursor);
}

t_token	*input(void)
{
	int			c;
	t_cursor	cursor;

	cursor.on_token = create_token(EOL);
	cursor.pos = get_cursor_pos();
	while (1)
	{
		c = ft_getch();
		if (c != ERR)
		{
			if (c == '\n')
				break ;
			else if (!ft_iscntrl(c))
				insert_token(&cursor, c);
			else
				control_key(&cursor, c);
		}
	}
	return (tokens_head(&cursor));
}

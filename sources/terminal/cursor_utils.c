/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:32:48 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/02 17:10:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Move position of cursor to the right. */
void	cursor_move_right(t_cursor *cursor)
{
	struct winsize	win;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	if (cursor->pos.y == win.ws_col - 1)
	{
		if (cursor->pos.x < win.ws_row - 1)
		{
			cursor->pos.x++;
			cursor->pos.y = 0;
		}
		else
		{
			tputs(tgetstr("sf", NULL), 1, ft_putchar_err);
			cursor->pos.y = 0;
		}
	}
	else
		cursor->pos.y++;
}

/* Move position of cursor to the left. */
void	cursor_move_left(t_cursor *cursor)
{
	struct winsize	win;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	if (cursor->pos.y == 0)
	{
		if (cursor->pos.x != 0)
		{
			cursor->pos.x--;
			cursor->pos.y = win.ws_col - 1;
		}
	}
	else
		cursor->pos.y--;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:32:48 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/15 04:59:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Move position of cursor to the right. */
int	cursor_move_right(t_cursor *cursor)
{
	struct winsize	win;
	int				inc;

	inc = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	if (cursor->pos.y == win.ws_col - 1)
	{
		if (cursor->pos.x < win.ws_row - 1)
		{
			cursor->pos.x++;
			cursor->pos.y = 0;
			inc = 1;
		}
		else
		{
			tputs(tgetstr("sf", NULL), 1, ft_putchar_err);
			cursor->pos.y = 0;
		}
	}
	else
		cursor->pos.y++;
	return (inc);
}

/* Move position of cursor to the left. */
int	cursor_move_left(t_cursor *cursor)
{
	int				dec;
	struct winsize	win;

	dec = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	if (cursor->pos.y == 0)
	{
		if (cursor->pos.x > 0)
		{
			cursor->pos.x--;
			cursor->pos.y = win.ws_col - 1;
			dec = 1;
		}
	}
	else
		cursor->pos.y--;
	return (dec);
}

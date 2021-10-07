/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:53:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/04 08:24:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	atoi_pos(t_axe *pos, int sep, int c)
{
	if (sep == false)
		pos->x = pos->x * 10 + (c - '0');
	else
		pos->y = pos->y * 10 + (c - '0');
}

static void	interupt_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGWINCH, SIG_IGN);
}

/* Return postion of cursor in terminal. */
t_axe	get_cursor_pos(void)
{
	char		c;
	int			sep;
	t_axe		pos;
	t_term		*term;

	c = 0;
	sep = false;
	interupt_signals();
	term = set_termios();
	pos = (t_axe){.x = 0, .y = 0};
	ft_putstr_fd("\033[6n", STDIN_FILENO);
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == 'R')
			break ;
		else if (c == ';')
			sep = true;
		else if (c != ESC && c != '[')
			atoi_pos(&pos, sep, c);
	}
	pos.x--;
	pos.y--;
	handle_signals();
	tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
	return (pos);
}

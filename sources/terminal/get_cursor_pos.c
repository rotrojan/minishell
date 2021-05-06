/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:53:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/06 16:57:07 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_axe	read_pos(void)
{
	int		c;
	int		sep;
	t_axe	pos;

	pos.x = 0;
	pos.y = 0;
	sep = FALSE;
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == 'R')
			break ;
		else if (c == ';')
			sep = TRUE;
		else if (c != 27 && c != '[')
		{
			if (sep == FALSE)
				pos.x = pos.x * 10 + (c - '0');
			else
				pos.y = pos.y * 10 + (c - '0');
		}
	}
	return (pos);
}

t_axe	get_cursor_pos(void)
{
	t_axe			pos;
	t_term			*term;
	struct termios	tmp;

	term = getterm();
	tmp = term->current;
	tmp.c_cflag &= ~(CREAD);
	tcsetattr(STDIN_FILENO, TCSANOW, &tmp);
	ft_fprintf(STDIN_FILENO, "\033[6n");
	pos = read_pos();
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	return (pos);
}

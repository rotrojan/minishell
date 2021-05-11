/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:53:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/11 21:50:13 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* you must have set the terminal
to non-canonical and without echo before */
t_axe	get_cursor_pos(void)
{
	int		c;
	int		sep;
	t_axe	pos;

	c = 0;
	pos.x = 0;
	pos.y = 0;
	sep = FALSE;
	ft_fprintf(STDIN_FILENO, "\033[6n");
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == 'R')
			break ;
		else if (c == ';')
			sep = TRUE;
		else if (c != ESC && c != '[')
		{
			if (sep == FALSE)
				pos.x = pos.x * 10 + (c - '0');
			else
				pos.y = pos.y * 10 + (c - '0');
		}
	}
	return (pos);
}

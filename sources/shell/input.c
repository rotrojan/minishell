/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/10 02:04:55 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*input(void)
{
	int			c;
	t_cursor	cursor;
	t_token		*tokens;

	tokens = create_token(EOL);
	cursor.on_token = tokens;
	cursor.pos = get_cursor_pos();
	while (1)
	{
		c = ft_getch();
		if (c != ERR)
		{
			if (c == '\n')
				break ;
			else if (!ft_iscntrl(c))
			{
				insert_token(&tokens, &cursor, c);
				ft_putchar(c);
			}
		}
	}
	return (tokens);
}

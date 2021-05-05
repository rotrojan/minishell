/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 01:54:11 by lucocozz         ###   ########.fr       */
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
	while (read(STDIN_FILENO, &c, 1) == 1 && c != '\n')
	{
		if (!ft_iscntrl(c))
		{
			insert_token(&tokens, &cursor, c);
			ft_putchar(c);
		}
		else
			ft_printf("%d", c);
	}
	return (tokens);
}

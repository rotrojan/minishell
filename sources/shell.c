/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/04 14:36:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell(void)
{
	int			c;
	t_token		*tokens;
	t_cursor	cursor;

	tokens = NULL;
	cursor.on_token = NULL;
	while (1)
	{
		prompt();
		while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
		{
			if (ft_iscntrl(c))
				ft_printf("%d", c);
			else
			{
				cursor.on_token = insert_token(&tokens, cursor, c);
				ft_putchar(c);
			}
		}
		print_tokens(tokens);
	}
}

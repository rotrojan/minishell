/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 00:57:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell(void)
{
	int			c;
	t_token		*tokens;
	t_cursor	cursor;

	while (1)
	{
		tokens = create_token(EOL);
		cursor.on_token = tokens;
		prompt();
		while (read(STDIN_FILENO, &c, 1) == 1 && c != '\n')
		{
			if (!ft_iscntrl(c))
			{
				insert_token(&tokens, &cursor, c);
				ft_putchar(c);
				print_tokens(tokens);
			}
			else
				ft_printf("%d", c);
		}
		print_tokens(tokens);
		clear_tokens(&tokens);
	}
}

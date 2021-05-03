/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/03 03:19:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell(void)
{
	int	c;
	int	run;

	run = 1;
	while (run)
	{
		prompt();
		while (read(STDIN_FILENO, &c, 1) > 0)
		{
			if (c == '\004')
			{
				run = 0;
				break ;
			}
			else
				ft_putchar(c);
		}
	}
}

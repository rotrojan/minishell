/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:13 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 19:38:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(int argc, char **argv)
{
	bool			has_dash_n_flag;
	unsigned int	i;

	has_dash_n_flag = (argc > 1 && ft_strcmp(argv[1], "-n") == 0);
	if (has_dash_n_flag == TRUE)
		i = 2;
	else
		i = 1;
	while (argv[i] != NULL)
	{
		ft_putstr(argv[i]);
		++i;
		if (argv[i] != NULL)
			ft_putchar(' ');
	}
	if (has_dash_n_flag == FALSE)
		ft_putchar('\n');
	return (0);
}

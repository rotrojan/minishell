/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:13 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 22:20:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_arg_is_dash_n(char *arg)
{
	if (*arg != '-')
		return (false);
	else
		++arg;
	while (*arg == 'n')
		++arg;
	if (*arg != '\0')
		return (false);
	return (true);
}

static int	index_first_arg_to_print(char **argv, bool *has_dash_n_flag)
{
	int	i;

	i = 1;
	while (argv[i] != NULL && check_arg_is_dash_n(argv[i]) == true)
	{
		*has_dash_n_flag = true;
		++i;
	}
	return (i);
}

int	ft_echo(int argc, char **argv)
{
	bool			has_dash_n_flag;
	unsigned int	i;

	(void)argc;
	has_dash_n_flag = false;
	i = index_first_arg_to_print(argv, &has_dash_n_flag);
	while (argv[i] != NULL)
	{
		ft_putstr(argv[i]);
		++i;
		if (argv[i] != NULL)
			ft_putchar(' ');
	}
	if (has_dash_n_flag == false)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}

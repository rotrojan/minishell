/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/16 17:39:21 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_status(int argc, char **argv)
{
	int	status;

	status = *get_exit_value();
	if (argc >= 2)
	{
		if (ft_isnumber(argv[1]) == 0)
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: exit: %s: numeric argument required\n", argv[1]);
			status = 2;
		}
		else if (argc > 2)
		{
			ft_dprintf(STDERR_FILENO, "minishell: exit: too many arguments\n");
			return (EXIT_FAILURE);
		}
		else
			status = ft_atoi(argv[1]);
	}
	return (status);
}

int	ft_exit(int argc, char **argv)
{
	int		status;
	bool	piped;

	piped = *get_is_piped();
	if (piped == false)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	status = get_status(argc, argv);
	if (piped == false)
		exit_shell(status, NULL);
	return (status);
}

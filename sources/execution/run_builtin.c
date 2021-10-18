/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 01:35:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/18 16:00:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_builtin(int argc, char **argv, t_IO_file save)
{
	int					i;
	t_builtins const	builtins[] = {
		{.name = "cd", .function = &cd},
		{.name = "echo", .function = &ft_echo},
		{.name = "env", .function = &ft_env},
		{.name = "exit", .function = &ft_exit},
		{.name = "pwd", .function = &pwd},
		{.name = "export", .function = &export},
		{.name = "unset", .function = &unset},
		{.name = NULL}
	};

	i = 0;
	if (ft_strcmp(argv[0], "exit") == 0)
		close_io(save);
	while (builtins[i].name != NULL && ft_strcmp(argv[0], builtins[i].name))
		i++;
	if (builtins[i].name == NULL)
		return (EXIT_CMD_NOT_FOUND);
	set_exit_value(builtins[i].function(argc, argv));
	return (EXIT_SUCCESS);
}

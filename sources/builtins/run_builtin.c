/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 01:35:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/13 15:07:14 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_builtin(int argc, char **argv, char **env)
{
	int					i;
	t_builtins const	builtins[] = {
		{.name = "cd", .function = &cd},
		{.name = "echo", .function = &ft_echo},
		{.name = "env", .function = &ft_env},
		{.name = "exit", .function = &ft_exit},
		{.name = "pwd", .function = &pwd},
		{.name = "unset", .function = &unset},
		{.name = NULL}
	};

	i = 0;
	while (builtins[i].name != NULL && ft_strcmp(argv[0], builtins[i].name))
		i++;
	if (builtins[i].name == NULL)
		return (-1);
	return (builtins[i].function(argc, argv, env));
}

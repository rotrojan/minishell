/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 01:35:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 07:55:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_builtin(int argc, char **argv)
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
	while (builtins[i].name != NULL && ft_strcmp(argv[0], builtins[i].name))
		i++;
	if (builtins[i].name == NULL)
		return (return_exit_value(EXIT_CMD_NOT_FOUND));
	return (return_exit_value(builtins[i].function(argc, argv)));
}

static void	child(int argc, char **argv)
{
	exit(exec_builtin(argc, argv));
}

static int	parent(void)
{
	int		status;

	wait(&status);
	return (WEXITSTATUS(status));
}

int	run_builtin(int argc, char **argv)
{
	pid_t	pid;

	if (*get_is_piped() == false)
		return (exec_builtin(argc, argv));
	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	else if (pid == 0)
		child(argc, argv);
	else
		return (parent());
	return (EXIT_FAILURE);
}

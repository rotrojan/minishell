/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:27:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/07 21:31:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(t_simple_cmd command)
{
	if (run_binary(command.argv) == -1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: command not found: %s\n",
			command.argv[0]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static void	parent(void)
{
	int		status;

	signal(SIGINT, SIG_IGN);
	wait(&status);
	if (WIFSIGNALED(status) && WTERMSIG(status) == CTRL_C)
		ft_putchar('\n');
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_STOP)
			exit_shell(EXIT_SUCCESS, NULL);
	}
}

void	exec_simple_cmd(t_simple_cmd command)
{
	pid_t	pid;
	int		save_in;
	int		save_out;

	save_in = dup(STDIN_FILENO);
	save_out = dup(STDOUT_FILENO);
	if (redirection(command) == -1)
		return ;
	if (run_builtin(command.argc, command.argv) == -1)
	{
		pid = fork();
		if (pid == ERR)
			exit_shell(EXIT_FAILURE, strerror(errno));
		else if (pid == 0)
			child(command);
		else
			parent();
	}
	dup2(save_in, STDIN_FILENO);
	dup2(save_out, STDOUT_FILENO);
}

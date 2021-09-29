/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:27:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/29 07:56:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(t_simple_cmd command)
{
	int	ret;

	ret = run_binary(command.argv);
	if (ret == EXIT_PERM_DENIED)
		ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n",
			command.argv[0], strerror(errno));
	else if (ret == EXIT_CMD_NOT_FOUND)
		ft_dprintf(STDERR_FILENO, "minishell: %s: command not found\n",
			command.argv[0]);
	exit(ret);
}

static void	parent(void)
{
	int		*sig;
	int		status;

	sig = get_signal_on();
	signal(SIGINT, SIG_IGN);
	wait(&status);
	if (WIFSIGNALED(status) && WTERMSIG(status) == CTRL_C)
	{
		*sig = SIGINT;
		ft_putchar('\n');
		set_exit_value(EXIT_CTRL_C_VALUE);
	}
	if (WIFEXITED(status))
		set_exit_value(WEXITSTATUS(status));
}

void	exec_simple_cmd(t_simple_cmd command)
{
	pid_t		pid;
	t_IO_file	save;

	save.input = dup(STDIN_FILENO);
	save.output = dup(STDOUT_FILENO);
	if (redirection(command) == -1)
		return ;
	if (command.argv[0] != NULL && command.argv[0][0] != '\0'
		&& run_builtin(command.argc, command.argv) == EXIT_CMD_NOT_FOUND)
	{
		pid = fork();
		if (pid == ERR)
			exit_shell(EXIT_FAILURE, strerror(errno));
		else if (pid == 0)
			child(command);
		else
			parent();
	}
	dup2(save.input, STDIN_FILENO);
	dup2(save.output, STDOUT_FILENO);
	close(save.input);
	close(save.output);
	close_redirections(command.input_redir);
	close_redirections(command.output_redir);
}

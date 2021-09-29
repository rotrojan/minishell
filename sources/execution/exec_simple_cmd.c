/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:27:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/29 04:19:04 by rotrojan         ###   ########.fr       */
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
	pid_t	pid;
	int		save_in;
	int		save_out;

	save_in = dup(STDIN_FILENO);
	save_out = dup(STDOUT_FILENO);
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
	dup2(save_in, STDIN_FILENO);
	dup2(save_out, STDOUT_FILENO);
	close(save_in);
	close(save_out);
	close_redirections(command.input_redir);
	close_redirections(command.output_redir);
}

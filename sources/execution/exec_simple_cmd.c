/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:27:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/12 18:07:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	run_binarie(char **argv, char **env)
{
	char	*bin_path;

	bin_path = getbinpath(argv[0]);
	if (bin_path == NULL)
		return (-1);
	execve(bin_path, argv, env);
	gc_free(bin_path);
	return (0);
}

static void	child(t_simple_cmd command, char **env)
{
	if (run_builtin(command.argc, command.argv, env) == -1)
	{
		if (run_binarie(command.argv, env) == -1)
		{
			ft_fprintf(STDERR_FILENO, "minishell: command not found: %s\n",
				command.argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}

static void	parent(void)
{
	int		status;

	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_STOP)
		exit_shell(EXIT_SUCCESS, NULL);
	if (WIFSIGNALED(status) && WTERMSIG(status) == CTRL_C)
		ft_fflush(STDIN_FILENO);
}

void	exec_simple_cmd(t_simple_cmd simple_cmd)
{
	pid_t	pid;
	t_env	*env;

	env = get_shell_env();
	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	else if (pid == Child)
		child(simple_cmd, *env);
	else
		parent();
}

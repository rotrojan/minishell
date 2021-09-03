/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:27:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/03 22:33:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_real_filepath(char const *filepath)
{
	char	*path;
	char	*real_path;
	char	*bin_path;

	path = extract_path(filepath);
	if (path == NULL)
		return (NULL);
	real_path = ft_realpath(path);
	if (real_path == NULL)
		return (NULL);
	bin_path = ft_strjoin(real_path, &filepath[ft_strlen(path)], "");
	gc_free(path);
	free(real_path);
	return (bin_path);
}

static int	run_binarie(char **argv)
{
	char	*bin_path;
	t_env	*env;

	env = get_shell_env();
	if (ft_strstr(argv[0], "./") != NULL)
	{
		bin_path = get_real_filepath(argv[0]);
		if (bin_path == NULL)
			return (-1);
	}
	else
		bin_path = getbinpath(argv[0]);
	if (bin_path == NULL)
		return (-1);
	if (execve(bin_path, argv, *env) == -1)
	{
		gc_free(bin_path);
		return (-1);
	}
	gc_free(bin_path);
	return (0);
}

static void	child(t_simple_cmd command)
{
	if (run_binarie(command.argv) == -1)
	{
		ft_fprintf(STDERR_FILENO, "minishell: command not found: %s\n",
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

void	exec_simple_cmd(t_simple_cmd simple_cmd)
{
	pid_t	pid;

	if (run_builtin(simple_cmd.argc, simple_cmd.argv) == -1)
	{
		pid = fork();
		if (pid == ERR)
			exit_shell(EXIT_FAILURE, strerror(errno));
		else if (pid == Child)
			child(simple_cmd);
		else
			parent();
	}
}

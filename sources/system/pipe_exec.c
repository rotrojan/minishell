/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:58:45 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/04 17:18:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(int *fd, const char *bin_path, const char **arg)
{
	close(fd[Output]);
	dup2(fd[Input], STDOUT_FILENO);
	execve(bin_path, (char *const *)arg, NULL);
	dup2(STDOUT_FILENO, fd[Input]);
	close(fd[Input]);
}

static t_file	parent(int *fd)
{
	t_file	output;

	close(fd[Input]);
	output = readfile(fd[Output]);
	close(fd[Output]);
	return (output);
}

/* Return piped output of another program. */
char	**pipe_exec(const char *bin_path, const char **arg)
{
	int			fd[2];
	pid_t		pid;
	t_file		output;

	output = NULL;
	if (pipe(fd) == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	else if (pid == 0)
		child(fd, bin_path, arg);
	else
		output = parent(fd);
	waitpid(pid, NULL, 0);
	return (output);
}

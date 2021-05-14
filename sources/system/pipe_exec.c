/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:58:45 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/14 01:28:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pipe_exec(char *bin_path, char **arg)
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
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(bin_path, arg, NULL);
		dup2(STDOUT_FILENO, fd[1]);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		output = readfile(fd[0]);
		close(fd[0]);
	}
	return (output);
}

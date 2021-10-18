/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:58:21 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/18 17:31:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_IO_file	*get_io(void)
{
	static t_IO_file	save =
	{
		.input = -1,
		.output = -1
	};

	return (&save);
}

static void	child(t_node *ast, int fd[2], t_IO_file *save)
{
	close(fd[Output]);
	dup2(fd[Input], STDOUT_FILENO);
	close(fd[Input]);
	close(save->input);
	save->input = -1;
	close(save->output);
	save->output = -1;
	exec_ast(ast->content.child.left, true);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	close(STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

static void	parent(t_node *ast, int fd[2], t_IO_file *save)
{
	signal(SIGINT, SIG_IGN);
	close(fd[Input]);
	dup2(fd[Output], STDIN_FILENO);
	close(fd[Output]);
	exec_ast(ast->content.child.right, true);
	close(STDIN_FILENO);
	wait(NULL);
	dup2(save->input, STDIN_FILENO);
	dup2(save->output, STDOUT_FILENO);
	close(save->input);
	save->input = -1;
	close(save->output);
	save->output = -1;
}

void	exec_pipe(t_node *ast)
{
	int			fd[2];
	pid_t		pid;
	t_IO_file	*save;

	save = get_io();
	save->input = dup(STDIN_FILENO);
	save->output = dup(STDOUT_FILENO);
	if (pipe(fd) == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	if (pid == 0)
		child(ast, fd, save);
	else
		parent(ast, fd, save);
}

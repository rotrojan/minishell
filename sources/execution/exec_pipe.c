/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:58:21 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/02 21:10:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(t_node *ast, int fd[2], t_IO_file save)
{
	close(fd[Output]);
	dup2(fd[Input], STDOUT_FILENO);
	close(fd[Input]);
	close(save.input);
	close(save.output);
	exec_ast(ast->content.child.left, true);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	close(STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

static void	parent(t_node *ast, int fd[2], t_IO_file save)
{
	signal(SIGINT, SIG_IGN);
	close(fd[Input]);
	dup2(fd[Output], STDIN_FILENO);
	close(fd[Output]);
	exec_simple_cmd(ast->content.child.right->content.simple_cmd);
	close(STDIN_FILENO);
	wait(NULL);
	dup2(save.input, STDIN_FILENO);
	dup2(save.output, STDOUT_FILENO);
	close(save.input);
	close(save.output);
}

void	exec_pipe(t_node *ast)
{
	int			fd[2];
	pid_t		pid;
	t_IO_file	save;

	save.input = dup(STDIN_FILENO);
	save.output = dup(STDOUT_FILENO);
	set_is_piped(true);
	if (pipe(fd) == -1)
		exit_shell(EXIT_FAILURE, strerror(errno));
	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	if (pid == 0)
		child(ast, fd, save);
	else
		parent(ast, fd, save);
}

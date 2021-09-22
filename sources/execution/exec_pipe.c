/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:58:21 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/22 02:19:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(t_node *ast, int fd[2], int save_in, int save_out)
{
	close(fd[Output]);
	dup2(fd[Input], STDOUT_FILENO);
	close(fd[Input]);
	close(save_in);
	close(save_out);
	exec_ast(ast->content.child.left, true);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	close(STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

static void	parent(t_node *ast, int fd[2], int save_in, int save_out)
{
	signal(SIGINT, SIG_IGN);
	close(fd[Input]);
	dup2(fd[Output], STDIN_FILENO);
	close(fd[Output]);
	exec_simple_cmd(ast->content.child.right->content.simple_cmd);
	close(STDIN_FILENO);
	wait(NULL);
	dup2(save_in, STDIN_FILENO);
	dup2(save_out, STDOUT_FILENO);
	close(save_in);
	close(save_out);
}

void	exec_pipe(t_node *ast)
{
	int		fd[2];
	pid_t	pid;
	int		save_in;
	int		save_out;

	save_in = dup(STDIN_FILENO);
	save_out = dup(STDOUT_FILENO);
	if (pipe(fd) == -1)
		exit_shell(EXIT_FAILURE, strerror(errno));
	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	if (pid == 0)
		child(ast, fd, save_in, save_out);
	else
		parent(ast, fd, save_in, save_out);
}

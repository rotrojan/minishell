/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:27:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/05 03:29:49 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_simple_cmd(t_simple_cmd simple_cmd)
{
	pid_t	pid;
	t_env	*env;

	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	else if (pid == Child)
	{
		env = get_shell_env();
		execve(getbinpath(simple_cmd.argv[0]), simple_cmd.argv, *env);
	}
	else
		handle_signals();
	waitpid(pid, NULL, 0);
}

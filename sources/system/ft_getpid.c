/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:12:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/04 18:52:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getpgrep(char *bin_path, char **arg)
{
	int			fd[2];
	pid_t		pid;
	char		*pgrep;

	pgrep = NULL;
	if (pipe(fd) == ERR)
		ft_exit(EXIT_FAILURE, strerror(errno));
	pid = fork();
	if (pid == ERR)
		ft_exit(EXIT_FAILURE, strerror(errno));
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
		get_next_line(fd[0], &pgrep);
		close(fd[0]);
	}
	return (pgrep);
}

pid_t	ft_getpid(void)
{
	pid_t		pid;
	char		*pgrep;
	char		*bin_path;
	static char	*arg[] = {"pgrep", "-n", "minishell", NULL};

	bin_path = getbinpath(arg[0]);
	if (!bin_path)
		ft_exit(EXIT_FAILURE, "ft_getbinpath(): No path found.");
	pgrep = getpgrep(bin_path, arg);
	pid = ft_atoi(pgrep);
	w_free(pgrep);
	return (pid);
}

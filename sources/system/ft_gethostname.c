/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethostname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:31:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 01:56:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_gethostname(void)
{
	int			fd[2];
	pid_t		pid;
	char		*hostname;
	char		*bin_path;
	static char	*arg[] = {"cat", "/etc/hostname", NULL};

	hostname = NULL;
	bin_path = ft_getbinpath(arg[0]);
	if (!bin_path)
		ft_exit_error("ft_getbinpath(): No path found.\n");
	if (pipe(fd) == ERR)
		ft_exit_error(strerror(errno));
	pid = fork();
	if (pid == ERR)
		ft_exit_error(strerror(errno));
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
		get_next_line(fd[0], &hostname);
		close(fd[0]);
	}
	if (pid != 0)
		wait(&pid);
	free(bin_path);
	ft_putstr(hostname);
	return (hostname);
}

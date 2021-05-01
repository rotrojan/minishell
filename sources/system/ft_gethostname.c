/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethostname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:31:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 02:14:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_getcat(char *bin_path, char **arg)
{
	int			fd[2];
	pid_t		pid;
	char		*hostname;

	hostname = NULL;
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
	return (hostname);
}

char	*ft_gethostname(void)
{
	char		*hostname;
	char		*bin_path;
	static char	*arg[] = {"cat", "/etc/hostname", NULL};

	bin_path = ft_getbinpath(arg[0]);
	if (!bin_path)
		ft_exit_error("ft_getbinpath(): No path found.\n");
	hostname = ft_getcat(bin_path, arg);
	free(bin_path);
	return (hostname);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:12:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 15:13:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return pid of program. */
pid_t	ft_getpid(void)
{
	t_file		output;
	pid_t		pid;
	char		*bin_path;
	char const	*arg[] = {"pgrep", "-n", "minishell", NULL};

	bin_path = getbinpath(arg[0]);
	if (!bin_path)
		exit_shell(EXIT_FAILURE, "ft_getbinpath(): No path found.\n");
	output = pipe_exec(bin_path, arg);
	if (output == NULL)
		exit_shell(EXIT_FAILURE, "pipe_exec(): can't get output.\n");
	pid = ft_atoi(output[0]);
	free_file(output);
	return (pid);
}

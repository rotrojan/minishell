/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethostname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:31:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 14:01:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return hostname of computer.
Only work in linux. */
char	*ft_gethostname(void)
{
	t_file		output;
	char		*bin_path;
	char		*hostname;
	static char	*arg[] = {"cat", "/etc/hostname", NULL};

	bin_path = getbinpath(arg[0]);
	if (!bin_path)
		exit_shell(EXIT_FAILURE, "ft_getbinpath(): No path found.\n");
	output = pipe_exec(bin_path, arg);
	if (output == NULL)
		exit_shell(EXIT_FAILURE, "pipe_exec(): can't get output.\n");
	hostname = ft_strdup(output[0]);
	free_file(output);
	gc_free(bin_path);
	return (hostname);
}

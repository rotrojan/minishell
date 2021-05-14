/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:58:54 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/14 01:26:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_os_name	getos(void)
{
	t_file			output;
	char			*bin_path;
	enum e_os_name	os_name;
	static char		*arg[] = {"uname", NULL};

	os_name = Linux;
	bin_path = getbinpath(arg[0]);
	if (!bin_path)
		exit_shell(EXIT_FAILURE, "ft_getbinpath(): No path found.\n");
	output = pipe_exec(bin_path, arg);
	if (output == NULL)
		exit_shell(EXIT_FAILURE, "pipe_exec(): can't get output.\n");
	if (ft_strcmp(output[0], "Darwin") == 0)
		os_name = Darwin;
	else if (ft_strcmp(output[0], "Linux") == 0)
		os_name = Linux;
	free_file(output);
	return (os_name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:58:54 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/11 22:16:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_os_name	getos(void)
{
	enum e_os_name	os_name;
	char			*uname;
	char			*bin_path;
	static char		*arg[] = {"uname", NULL};

	os_name = Linux;
	bin_path = getbinpath(arg[0]);
	if (!bin_path)
		exit_shell(EXIT_FAILURE, "ft_getbinpath(): No path found.\n");
	uname = pipe_exec(bin_path, arg);
	if (ft_strcmp(uname, "Darwin") == 0)
		os_name = Darwin;
	else if (ft_strcmp(uname, "Linux") == 0)
		os_name = Linux;
	gc_free(uname);
	return (os_name);
}

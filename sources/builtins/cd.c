/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/24 23:44:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(const char *path)
{
	char		*new;
	char		*old;

	if (chdir(path) != -1)
	{
		new = getcwd(NULL, 0);
		if (new == NULL)
			exit_shell(EXIT_FAILURE, "getcwd(): failed to get pwd.");
		old = ft_getenv("PWD");
		ft_setenv("OLDPWD", old, 1);
		ft_setenv("PWD", new, 1);
		ft_printf("%s\n", new);
		free(new);
	}
	else
		ft_printf("cd: no file or directory of type: %s\n", path);
}

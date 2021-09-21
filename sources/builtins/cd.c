/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/21 20:56:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(int argc, char **argv)
{
	char		new[PATH_MAX];
	char		old[PATH_MAX];
	char		*tmp;

	(void)argc;
	if (argv[1] == NULL)
		tmp = ft_getenv("HOME");
	else
		tmp = argv[1];
	if (getcwd(old, PATH_MAX) == NULL)
		exit_shell(EXIT_FAILURE, "getcwd(): failed to get pwd.");
	if (chdir(tmp) != -1)
	{
		if (getcwd(new, PATH_MAX) == NULL)
			exit_shell(EXIT_FAILURE, "getcwd(): failed to get pwd.");
		ft_setenv("OLDPWD", old, 1);
		ft_setenv("PWD", new, 1);
		if (argv[1] != NULL)
			ft_printf("%s\n", new);
	}
	else
	{
		ft_printf("cd: no file or directory of type: %s\n", tmp);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

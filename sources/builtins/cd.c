/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/06 02:15:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(int argc, char **argv, char **env)
{
	char		*new;
	char		*old;
	char		*tmp;

	(void)(argc && env);
	if (argv[1] == NULL)
		tmp = ft_getenv("HOME");
	else
		tmp = argv[1];
	if (chdir(tmp) != -1)
	{
		new = getcwd(NULL, 0);
		if (new == NULL)
			exit_shell(EXIT_FAILURE, "getcwd(): failed to get pwd.");
		old = ft_getenv("PWD");
		ft_setenv("OLDPWD", old, 1);
		ft_setenv("PWD", new, 1);
		if (argv[1] != NULL)
			ft_printf("%s\n", new);
		free(new);
	}
	else
		ft_printf("cd: no file or directory of type: %s\n", tmp);
	return (0);
}

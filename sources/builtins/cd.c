/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 04:18:00 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(int argc, char **argv)
{
	char		*path;
	char		new[PATH_MAX];
	char		old[PATH_MAX];

	(void)argc;
	if (argv[1] == NULL)
		path = ft_getenv("HOME");
	else
		path = argv[1];
	if (getcwd(old, PATH_MAX) != NULL)
		ft_setenv("OLDPWD", old, 1);
	if (chdir(path) == -1)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: %s: No such file or directory\n", argv[0], argv[1],
			path);
		return (EXIT_FAILURE);
	}
	getcwd(new, PATH_MAX);
	ft_setenv("PWD", new, 1);
	return (EXIT_SUCCESS);
}

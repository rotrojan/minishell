/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/15 13:38:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_path(char **argv)
{
	char	*home;

	if (argv[1] == NULL)
	{
		home = ft_getenv("HOME");
		if (home == NULL)
		{
			ft_dprintf(STDERR_FILENO, "minishell: %s: HOME not set\n", argv[0]);
			return (NULL);
		}
		return (home);
	}
	else
		return (argv[1]);
}

static void	update_pwd(char **argv)
{
	char		new[SIZE_8B];
	char		*pwd;

	if (getcwd(new, SIZE_8B) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "pwd: error retrieving current directory: \
getcwd: cannot access parent directories: %s\n", strerror(errno));
		pwd = ft_strjoin(ft_getenv("PWD"), argv[1], "");
		ft_setenv("PWD", pwd, 1);
		gc_free((void **)&pwd);
	}
	else
		ft_setenv("PWD", new, 1);
}

int	cd(int argc, char **argv)
{
	char		*path;
	char		old[SIZE_8B];

	(void)argc;
	path = get_path(argv);
	if (path == NULL)
		return (EXIT_FAILURE);
	if (getcwd(old, SIZE_8B) != NULL)
		ft_setenv("OLDPWD", old, 1);
	if (chdir(path) == -1)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: %s: No such file or directory\n", argv[0], argv[1],
			path);
		return (EXIT_FAILURE);
	}
	update_pwd(argv);
	return (EXIT_SUCCESS);
}

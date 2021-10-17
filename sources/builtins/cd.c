/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/17 18:28:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cdpath(const char *dir)
{
	int			i;
	char		**paths;
	char		*cd_path;
	struct stat	buf;

	i = 0;
	paths = ft_split(ft_getenv("CDPATH"), ':');
	if (paths == NULL)
		return (NULL);
	while (paths[i])
	{
		cd_path = ft_strjoin(paths[i], dir, "/");
		if (lstat(cd_path, &buf) == 0)
		{
			ft_free_arrays(paths);
			return (cd_path);
		}
		gc_free((void **)&cd_path);
		i++;
	}
	ft_free_arrays(paths);
	return (NULL);
}

static char	*get_path(char **argv)
{
	char	*home;
	char	*cd_path;

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
	{
		cd_path = get_cdpath(argv[1]);
		if (cd_path == NULL)
			return (argv[1]);
		else
			return (cd_path);
	}
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

	if (argc > 2)
	{
		ft_dprintf(STDERR_FILENO, "minishell: cd: too many arguments");
		return (EXIT_FAILURE);
	}
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

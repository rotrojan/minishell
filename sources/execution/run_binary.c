/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:01:28 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/10 16:47:23 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_access(char **bin_path)
{
	if (access(*bin_path, X_OK) == -1)
	{
		gc_free((void **)bin_path);
		return (false);
	}
	return (true);
}

static char	*get_binpath(char **argv)
{
	if (ft_strstr(argv[0], "./") != NULL)
		return (get_real_filepath(argv[0]));
	else if (ft_strchr(argv[0], '/') != NULL)
		return (ft_strdup(argv[0]));
	else
		return (getbinpath(argv[0]));
}

static bool	is_directory(char **bin_path)
{
	struct stat	data;

	stat(*bin_path, &data);
	if (S_ISDIR(data.st_mode) == 1)
	{
		gc_free((void **)bin_path);
		return (true);
	}
	return (false);
}

int	run_binary(char **argv)
{
	char	*bin_path;
	t_env	*env;

	env = get_shell_env();
	bin_path = get_binpath(argv);
	if (bin_path == NULL)
		return (EXIT_CMD_NOT_FOUND);
	if (is_directory(&bin_path) == true)
	{
		errno = EISDIR;
		return (EXIT_EXEC_ERROR);
	}
	if (check_access(&bin_path) == false)
		return (EXIT_EXEC_ERROR);
	if (execve(bin_path, argv, *env) == -1)
	{
		gc_free((void **)&bin_path);
		return (EXIT_CMD_NOT_FOUND);
	}
	gc_free((void **)&bin_path);
	return (EXIT_SUCCESS);
}

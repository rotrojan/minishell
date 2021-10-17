/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:01:28 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/17 19:23:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*found_binpath(char **argv)
{
	if (ft_strstr(argv[0], "./") != NULL)
		return (get_real_filepath(argv[0]));
	else if (ft_strchr(argv[0], '/') != NULL)
		return (ft_strdup(argv[0]));
	else
		return (getbinpath(argv[0]));
}

static int	manage_error(char *bin_path, char *command, char *error,
	int exit_value)
{
	gc_free((void **)&bin_path);
	ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", command, error);
	return (exit_value);
}

static int	manage_execution(char *bin_path, char *command)
{
	int	ret;

	if (bin_path == NULL)
	{
		if (ft_getenv("PATH") == NULL)
			return (manage_error(NULL, command, "No such file or directory",
					EXIT_CMD_NOT_FOUND));
		else
			return (manage_error(NULL, command, "command not found",
					EXIT_CMD_NOT_FOUND));
	}
	ret = is_directory(bin_path);
	if (ret == 1)
		return (manage_error(bin_path, command, "Is a directory",
				EXIT_EXEC_ERROR));
	else if (ret == -1)
		return (manage_error(bin_path, command, strerror(errno),
				EXIT_CMD_NOT_FOUND));
	if (is_executable(bin_path) == false)
		return (manage_error(bin_path, command, strerror(errno),
				EXIT_EXEC_ERROR));
	return (EXIT_SUCCESS);
}

int	run_binary(char **argv)
{
	int		ret;
	char	*bin_path;
	t_env	*env;

	env = get_shell_env();
	bin_path = found_binpath(argv);
	ret = manage_execution(bin_path, argv[0]);
	if (ret != EXIT_SUCCESS)
		return (ret);
	if (execve(bin_path, argv, *env) == -1)
		return (manage_error(bin_path, argv[0], strerror(errno),
				EXIT_EXEC_ERROR));
	gc_free((void **)&bin_path);
	return (EXIT_SUCCESS);
}

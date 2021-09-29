/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:01:28 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 04:43:51 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_permission(char **bin_path)
{
	if (access(*bin_path, X_OK) == -1)
	{
		gc_free((void **)bin_path);
		return (false);
	}
	return (true);
}

int	run_binary(char **argv)
{
	char	*bin_path;
	t_env	*env;

	env = get_shell_env();
	if (ft_strstr(argv[0], "./") != NULL)
	{
		bin_path = get_real_filepath(argv[0]);
		if (bin_path == NULL)
			return (EXIT_CMD_NOT_FOUND);
	}
	else if (ft_strchr(argv[0], '/') != NULL)
		bin_path = ft_strdup(argv[0]);
	else
		bin_path = getbinpath(argv[0]);
	if (bin_path == NULL)
		return (EXIT_CMD_NOT_FOUND);
	if (check_permission(&bin_path) == false)
		return (EXIT_PERM_DENIED);
	if (execve(bin_path, argv, *env) == -1)
	{
		gc_free((void **)&bin_path);
		return (EXIT_CMD_NOT_FOUND);
	}
	gc_free((void **)&bin_path);
	return (EXIT_SUCCESS);
}

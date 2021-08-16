/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:25:45 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/16 17:35:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_path(char const *pathfile)
{
	int	i;

	i = ft_strlen(pathfile);
	while (i > 0 && pathfile[i] != '/')
		i--;
	if (i == 0)
		return (NULL);
	return (ft_strndup(pathfile, i));
}

char	*ft_realpath(char const *path)
{
	char	*real_path;
	char	pwd[PATH_MAX];

	if (chdir(path) == -1)
		return (NULL);
	real_path = getcwd(NULL, 0);
	if (real_path == NULL)
		exit_shell(EXIT_FAILURE, "getcwd(): failed to get pwd.");
	getcwd(pwd, PATH_MAX);
	if (chdir(pwd) == -1)
	{
		free(real_path);
		exit_shell(EXIT_FAILURE, "chdir(): failed to reset pwd.");
	}
	return (real_path);
}

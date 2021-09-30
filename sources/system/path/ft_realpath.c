/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 05:44:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/30 05:45:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realpath(char const *path)
{
	char	*real_path;
	char	pwd[SIZE_8B];

	if (ft_strchr(path, '/') == NULL && chdir("./") == -1)
		return (NULL);
	if (chdir(path) == -1)
		return (NULL);
	real_path = getcwd(NULL, 0);
	if (real_path == NULL)
		exit_shell(EXIT_FAILURE, "getcwd(): failed to get pwd.");
	getcwd(pwd, SIZE_8B);
	if (chdir(pwd) == -1)
	{
		free(real_path);
		exit_shell(EXIT_FAILURE, "chdir(): failed to reset pwd.");
	}
	return (real_path);
}

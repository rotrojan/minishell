/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:39:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 01:17:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int argc, char **argv)
{
	char	path[PATH_MAX];

	(void)(argc && argv);
	if (getcwd(path, PATH_MAX) == NULL)
		ft_dprintf(STDERR_FILENO, "pwd: error retrieving current directory: \
getcwd: cannot access parent directories: %s", strerror(errno));
	ft_putstr(path);
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}

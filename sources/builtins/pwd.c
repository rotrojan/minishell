/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:39:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/30 03:20:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int argc, char **argv)
{
	char	path[SIZE_8B];

	(void)(argc && argv);
	if (getcwd(path, SIZE_8B) == NULL)
		ft_dprintf(STDERR_FILENO, "pwd: error retrieving current directory: \
getcwd: cannot access parent directories: %s", strerror(errno));
	ft_putstr(path);
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}

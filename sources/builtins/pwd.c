/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:39:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/16 17:34:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int argc, char **argv)
{
	char	path[PATH_MAX];

	(void)(argc && argv);
	getcwd(path, PATH_MAX);
	ft_putstr(path);
	ft_putchar('\n');
	return (0);
}

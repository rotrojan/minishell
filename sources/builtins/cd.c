/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 01:31:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_path(const char *path)
{
	char	*new;

	if (path[0] == '~')
		new = ft_strjoin(ft_getenv("HOME"), &path[1], "");
	else if (path[0] == '.')
		new = ft_strjoin(ft_getenv("PWD"), &path[1], "");
	else
		new = ft_strdup(path);
	return (new);
}

void	cd(const char *path)
{
	char		*new;
	char		*old;
	struct stat	buf;

	new = parse_path(path);
	if (stat(new, &buf) == 0 && S_ISDIR(buf.st_mode))
	{
		old = ft_getenv("PWD");
		ft_setenv("OLDPWD", old, 1);
		ft_setenv("PWD", new, 1);
		if (chdir(new) == -1)
			ft_printf("cd: can't access: %s\n", path);
	}
	else
		ft_printf("cd: aucun fichier ou dossier de ce type: %s\n", path);
	gc_free(new);
}

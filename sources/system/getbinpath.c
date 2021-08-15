/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbinpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:35:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 16:10:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return path of binarie, NULL if not found. */
char	*getbinpath(const char *bin)
{
	int			i;
	char		**paths;
	char		*bin_path;
	struct stat	buf;

	i = 0;
	paths = ft_split(ft_getenv("PATH"), ':');
	while (paths[i])
	{
		bin_path = ft_strjoin(paths[i], bin, "/");
		if (stat(bin_path, &buf) == 0)
		{
			ft_free_arrays(paths);
			return (bin_path);
		}
		gc_free(bin_path);
		i++;
	}
	ft_free_arrays(paths);
	return (NULL);
}

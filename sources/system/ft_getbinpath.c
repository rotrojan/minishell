/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbinpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:35:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 21:35:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getbinpath(char *bin)
{
	int			i;
	char		**paths;
	char		*bin_path;
	struct stat	buf;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i])
	{
		bin_path = ft_strjoin(paths[i], bin, "/");
		if (stat(bin_path, &buf) == 0)
		{
			ft_free_arrays(paths);
			return (bin_path);
		}
		free(bin_path);
		i++;
	}
	ft_free_arrays(paths);
	return (NULL);
}

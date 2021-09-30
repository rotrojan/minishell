/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_filepath.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 05:42:41 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/30 05:42:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_real_filepath(char const *filepath)
{
	char	*path;
	char	*real_path;
	char	*bin_path;

	path = extract_path(filepath);
	if (path == NULL)
		return (NULL);
	real_path = ft_realpath(path);
	if (real_path == NULL)
		return (NULL);
	bin_path = ft_strjoin(real_path, &filepath[ft_strlen(path)], "");
	gc_free((void **)&path);
	free(real_path);
	return (bin_path);
}

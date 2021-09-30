/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:25:45 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/30 07:20:13 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_file(char *pathfile)
{
	int	i;

	if (pathfile == NULL)
		return (NULL);
	if (ft_strchr(pathfile, '/') == NULL)
		return (pathfile);
	i = ft_strlen(pathfile);
	while (i > 0 && pathfile[i] != '/')
		i--;
	return (&pathfile[i + 1]);
}

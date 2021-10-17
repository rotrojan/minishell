/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:39:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/17 17:53:23 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(char *bin_path)
{
	struct stat	data;

	if (stat(bin_path, &data) == -1)
		return (-1);
	if (S_ISDIR(data.st_mode) == 1)
		return (1);
	return (0);
}

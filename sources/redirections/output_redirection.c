/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:19:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/08 17:13:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	output_redirection(char **args)
{
	int	flag;
	int	fd;

	if (ft_strcmp(">", *args) == 0)
		flag = O_TRUNC;
	else
		flag = O_APPEND;
	++args;
	fd = open(*args, O_WRONLY | O_CREAT | flag,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: No such file or directory\n",
			*args);
		set_exit_value(EXIT_FAILURE);
		return (-1);
	}
	return (fd);
}

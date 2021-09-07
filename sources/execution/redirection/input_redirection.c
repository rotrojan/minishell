/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:29:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 21:29:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_redirection(t_redirection *redirection)
{
	int	fd;

	fd = open(redirection->stream, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(STDOUT_FILENO, "minishell: %s: No such file or directory\n",
			redirection->stream);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	return (0);
}

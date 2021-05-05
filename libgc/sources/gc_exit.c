/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/05 15:10:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

static void	ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void	gc_exit(int status, char *message)
{
	gc_free_all();
	if (status == EXIT_SUCCESS && message != NULL)
		ft_putstr_fd(STDOUT_FILENO, message);
	else if (status == EXIT_FAILURE)
	{
		ft_putstr_fd(STDERR_FILENO, "Error: ");
		ft_putstr_fd(STDERR_FILENO, message);
	}
	exit(status);
}

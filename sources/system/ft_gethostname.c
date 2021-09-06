/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethostname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:31:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/17 19:13:53 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return hostname of computer.
Only work in linux. */
char	*ft_gethostname(void)
{
	int			fd;
	char		*hostname;

	hostname = NULL;
	fd = open("/etc/hostname", O_RDONLY);
	if (fd == -1)
		exit_shell(EXIT_FAILURE, strerror(errno));
	if (get_next_line(fd, &hostname) == -1)
		exit_shell(EXIT_FAILURE, "get_next_line(): read error.");
	return (hostname);
}

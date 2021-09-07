/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 03:42:24 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 21:05:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug(int tty_id, char *str, ...)
{
	int		fd;
	char	*id;
	char	*tty;
	va_list	ap;

	va_start(ap, str);
	id = ft_itoa(tty_id);
	tty = ft_strjoin(TTY_PATH, id, "");
	gc_free(id);
	fd = open(tty, O_RDWR);
	if (fd == -1)
		ft_dprintf(STDERR_FILENO, "Error: debug(): can't open tty=%s\n", tty);
	else
	{
		ft_putstr_fd("\r\n", fd);
		ft_vdprintf(fd, str, ap);
		close(fd);
	}
	gc_free(tty);
}

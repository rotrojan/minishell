/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 02:21:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/14 21:39:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fflush(int fd)
{
	char	c;
	int		ret;
	t_term	*term;

	ret = 1;
	term = getterm();
	set_timeout(term, 0);
	while (ret)
	{
		ret = read(fd, &c, 1);
		if (ret < 0)
			return (-1);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	return (0);
}

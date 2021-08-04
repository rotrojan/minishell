/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 02:21:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/04 02:32:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_timeout(t_term *term, int timeout)
{
	struct termios	tmp;

	tmp = term->current;
	tmp.c_cc[VMIN] = 0;
	tmp.c_cc[VTIME] = timeout;
	tcsetattr(STDIN_FILENO, TCSANOW, &tmp);
}

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
			return (EOF);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	return (0);
}

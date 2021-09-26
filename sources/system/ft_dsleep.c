/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:39:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/26 04:18:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(int time)
{
	char			c;
	t_term			*term;

	signal(SIGINT, SIG_IGN);
	ft_fflush(STDIN_FILENO);
	term = getterm();
	set_timeout(term, time);
	read(STDIN_FILENO, &c, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	exit(EXIT_SUCCESS);
}

void	parent(void)
{
	signal(SIGINT, SIG_IGN);
	wait(NULL);
}

void	ft_dsleep(int time)
{
	int	pid;

	pid = fork();
	if (pid == ERR)
		exit_shell(EXIT_FAILURE, strerror(errno));
	if (pid == 0)
		child(time);
	else
		parent();
}

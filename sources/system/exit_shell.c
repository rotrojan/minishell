/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 02:19:45 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 16:42:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int status, char *message)
{
	t_term	*term;

	term = getterm();
	tcsetattr(STDIN_FILENO, TCSANOW, &term->old);
	gc_exit(status, message);
}
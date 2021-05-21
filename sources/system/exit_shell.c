/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 02:19:45 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 14:03:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Exit shell, restoring default config of term
and free all memory used. */
void	exit_shell(int status, char *message)
{
	t_term	*term;

	term = getterm();
	tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
	gc_exit(status, message);
}

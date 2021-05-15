/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:06:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/15 20:32:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_in_history(t_inchar *inchars)
{
	int			fd;
	t_inchar	*tmp;

	fd = open(".history", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		exit_shell(EXIT_FAILURE, "open(): can't open .history file.\n");
	tmp = inchars;
	while (tmp->value != EOL)
	{
		write(fd, &tmp->value, 1);
		tmp = tmp->next;
	}
	write(fd, "\n", 1);
	close(fd);
}

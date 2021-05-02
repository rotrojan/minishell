/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 19:27:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgarbage.h"

void	exit_error(char *displayed_message, int errnum)
{
	t_garbage_lst	*current;
	t_garbage_lst	*next;

	current = *get_garbage_lst();
	while (current)
	{
		next = current->next;
		free(current->ptr);
		current->ptr = NULL;
		free(current);
		current = NULL;
		current = next;
	}
	if (errnum == 0)
		ft_fprintf(STDOUT_FILENO, "%s\n", displayed_message);
	else
		ft_fprintf(STDERR_FILENO, "Error: %s\n", displayed_message);
	exit(errnum);
}

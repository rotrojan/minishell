/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/03 01:02:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int errnum, char *message)
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
	if (errnum == EXIT_SUCCESS)
		ft_fprintf(STDOUT_FILENO, "%s\n", message);
	else
		ft_fprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(errnum);
}

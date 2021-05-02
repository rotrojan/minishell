/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by bigo              #+#    #+#             */
/*   Updated: 2021/05/02 03:41:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*w_alloc(size_t nmemb, size_t size, t_garbage_lst **garbage_lst)
{
	t_garbage_lst	*new_garbage;

	new_garbage = (t_garbage_lst *)malloc(sizeof(t_garbage_lst));
	new_garbage->garbage_ptr = malloc(nmemb * size);
	new_garbage->next = *garbage_lst;
	*garbage_lst = new_garbage;
	return (new_garbage->garbage_ptr);
}

void	w_free(void *garbage_to_free, t_garbage_lst **garbage_lst)
{
	t_garbage_lst	*current_garbage;
	t_garbage_lst	*previous_garbage;

	current_garbage = *garbage_lst;
	previous_garbage = NULL;
	while (current_garbage->garbage_ptr != garbage_to_free)
	{
		previous_garbage = current_garbage;
		current_garbage = current_garbage->next;
	}
	free(current_garbage->garbage_ptr);
	current_garbage->garbage_ptr = NULL;
	if (previous_garbage == NULL)
		*garbage_lst = current_garbage->next;
	else
		previous_garbage->next = current_garbage->next;
	free(current_garbage->garbage_ptr);
	current_garbage->garbage_ptr = NULL;
	free(current_garbage);
	current_garbage = NULL;
}

void	exit_error(char *str_error, t_garbage_lst **garbage_lst)
{
	int				ret;
	t_garbage_lst	*current_garbage;
	t_garbage_lst	*next_garbage;

	current_garbage = *garbage_lst;
	if (str_error == NULL)
	{
		ft_printf("Exit minishell\n");
		ret = EXIT_SUCCESS;
	}
	else
	{
		ft_printf("Error: %s\n", str_error);
		ret = EXIT_FAILURE;
	}
	while (current_garbage)
	{
		next_garbage = current_garbage->next;
		free(current_garbage->garbage_ptr);
		current_garbage->garbage_ptr = NULL;
		free(current_garbage);
		current_garbage = NULL;
		current_garbage = next_garbage;
	}
	exit(ret);
}

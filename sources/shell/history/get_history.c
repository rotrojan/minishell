/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 04:26:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/10 20:16:22 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return address of history data. */
t_history_data	*get_history(void)
{
	static t_history_data	history = {
		.data = NULL,
		.input = NULL,
		.tmp_nav = NULL
		};

	return (&history);
}

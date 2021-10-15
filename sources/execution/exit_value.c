/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:32:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/15 19:15:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_exit_value(void)
{
	static int	exit_value = 0;

	return (&exit_value);
}

void	set_exit_value(int exit_value)
{
	*get_exit_value() = exit_value;
}

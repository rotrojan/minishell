/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:32:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/21 21:15:21 by rotrojan         ###   ########.fr       */
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

int	return_exit_value(int exit_value)
{
	set_exit_value(exit_value);
	return (exit_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:32:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/21 02:01:22 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_last_return(void)
{
	static int	last_return = 0;

	return (&last_return);
}

void	set_last_return(int return_value)
{
	*get_last_return() = return_value;
}

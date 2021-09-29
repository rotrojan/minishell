/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_piped.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:39:09 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 07:55:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	*get_is_piped(void)
{
	static bool	is_piped = false;

	return (&is_piped);
}

void	set_is_piped(bool value)
{
	bool	*is_piped;

	is_piped = get_is_piped();
	*is_piped = value;
}

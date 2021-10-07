/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:52 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/05 14:46:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_line_count(void)
{
	static int	line_cout = 0;

	return (&line_cout);
}

int	increase_line_count(void)
{
	int	*line_cout;

	line_cout = get_line_count();
	*line_cout += 1;
	return (*line_cout);
}

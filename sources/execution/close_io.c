/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:35:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 17:36:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_io(t_IO_file save)
{
	dup2(save.input, STDIN_FILENO);
	dup2(save.output, STDOUT_FILENO);
	close(save.input);
	close(save.output);
}

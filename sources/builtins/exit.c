/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/21 23:04:13 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(int argc, char **argv)
{
	(void)(argc && argv);
	exit_shell(EXIT_SUCCESS, "exit\n");
	return (EXIT_FAILURE);
}

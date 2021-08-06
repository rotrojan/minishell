/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/06 02:19:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(int argc, char **argv, char **env)
{
	(void)(argc && argv && env);
	exit_shell(EXIT_SUCCESS, "\n");
	return (0);
}

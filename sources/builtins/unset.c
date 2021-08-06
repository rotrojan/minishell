/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:31:27 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/06 02:20:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(int argc, char **argv, char **env)
{
	(void)(argc && env);
	if (argv[1])
		ft_unsetenv(argv[1]);
	else
		ft_printf("unset: not enough arguments\n");
	return (0);
}

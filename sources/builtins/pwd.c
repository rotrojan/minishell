/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:39:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/06 00:49:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int argc, char **argv, char **env)
{
	(void)(argc && argv && env);
	ft_putstr(ft_getenv("PWD"));
	ft_putchar('\n');
	return (0);
}

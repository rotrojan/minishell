/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:39:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 16:04:39 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int argc, char **argv)
{
	(void)(argc && argv);
	ft_putstr(ft_getenv("PWD"));
	ft_putchar('\n');
	return (0);
}

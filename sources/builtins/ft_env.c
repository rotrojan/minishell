/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 16:04:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(int argc, char **argv)
{
	int		i;
	t_env	*env;

	(void)(argc && argv);
	i = 0;
	env = get_shell_env();
	while ((*env)[i])
	{
		ft_putstr((*env)[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

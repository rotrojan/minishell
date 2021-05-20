/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/20 23:56:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(void)
{
	int		i;
	t_env	tmp;
	t_env	*env;

	i = 0;
	env = get_shell_env();
	tmp = *env;
	while (tmp[i])
	{
		ft_putstr(tmp[i]);
		ft_putchar('\n');
		i++;
	}
}

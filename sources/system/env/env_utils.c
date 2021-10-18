/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:00:52 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/18 23:04:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return address of environment. */
t_env	*get_shell_env(void)
{
	static t_env	shell_env = NULL;

	return (&shell_env);
}

int	env_len(t_env env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

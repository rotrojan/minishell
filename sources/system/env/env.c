/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:00:52 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 14:21:19 by lucocozz         ###   ########.fr       */
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

/* Save environment in accessible memory */
void	init_shell_env(t_env env)
{	
	int		i;
	t_env	tmp;
	t_env	*shell_env;

	i = 0;
	shell_env = get_shell_env();
	if (*shell_env == NULL)
	{
		tmp = gc_malloc(sizeof(char *) * (env_len(env) + 1));
		while (env[i])
		{
			tmp[i] = ft_strdup(env[i]);
			i++;
		}
		tmp[i] = NULL;
		*shell_env = tmp;
	}
}

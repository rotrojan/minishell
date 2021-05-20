/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:01:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 01:31:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**add_in_env(const char *name, const char *value, t_env env)
{
	int		i;
	t_env	new;

	i = 0;
	new = gc_alloc(sizeof(char *) * (env_len(env) + 2));
	while (env[i])
	{
		new[i] = env[i];
		i++;
	}
	new[i++] = ft_strjoin(name, value, "=");
	new[i] = NULL;
	return (new);
}

void	ft_setenv(const char *name, const char *value, int overwrite)
{
	int		i;
	t_env	tmp;
	t_env	*env;

	env = get_shell_env();
	tmp = *env;
	i = ft_inenv(name);
	if (i >= 0 && overwrite != 0)
	{
		gc_free(tmp[i]);
		tmp[i] = ft_strjoin(name, value, "=");
	}
	else
	{
		*env = add_in_env(name, value, tmp);
		gc_free(tmp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:01:50 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/08 18:21:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**add_in_env(const char *name, const char *value, t_env env)
{
	int		i;
	t_env	new;

	i = 0;
	new = gc_malloc(sizeof(char *) * (env_len(env) + 2));
	while (env[i])
	{
		new[i] = env[i];
		i++;
	}
	if (value == NULL)
		new[i++] = ft_strjoin(name, value, "");
	else
		new[i++] = ft_strjoin(name, value, "=");
	new[i] = NULL;
	return (new);
}

/* Set VAR if not exist or if overwrite is not null value, else do nothing. */
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
		gc_free((void **)&tmp[i]);
		if (value == NULL)
			tmp[i] = ft_strjoin(name, value, "");
		else
			tmp[i] = ft_strjoin(name, value, "=");
	}
	else if (i < 0)
	{
		*env = add_in_env(name, value, tmp);
		gc_free((void **)&tmp);
	}
}

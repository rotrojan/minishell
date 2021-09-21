/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:00:52 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/21 22:34:35 by lucocozz         ###   ########.fr       */
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

static void	init_env_var(char *shell_name)
{
	char	*shlvl;
	char	*tmp_path;
	char	*shell_path;

	shlvl = ft_itoa(ft_atoi(ft_getenv("SHLVL")) + 1);
	tmp_path = ft_strjoin("./", shell_name, "");
	shell_path = get_real_filepath(tmp_path);
	ft_setenv("SHLVL", shlvl, 1);
	ft_setenv("SHELL", shell_path, 1);
	gc_free((void **)&tmp_path);
	gc_free((void **)&shell_path);
	gc_free((void **)&shlvl);
}

/* Save environment in accessible memory */
void	init_shell_env(char *shell_name, t_env env)
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
	init_env_var(shell_name);
}

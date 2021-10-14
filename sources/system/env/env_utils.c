/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:00:52 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/14 22:56:57 by lucocozz         ###   ########.fr       */
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
	char	pwd[SIZE_10B];
	char	*tmp_path;
	char	*shell_path;
	char	*shlvl_value;

	shlvl = ft_getenv("SHLVL");
	if (shlvl == NULL)
		shlvl = "0";
	shlvl_value = ft_itoa(ft_atoi(shlvl) + 1);
	tmp_path = ft_strjoin("./", shell_name, "");
	shell_path = get_real_filepath(tmp_path);
	ft_setenv("SHLVL", shlvl_value, 1);
	ft_setenv("SHELL", shell_path, 1);
	if (ft_getenv("PATH") == NULL)
		ft_setenv("PATH", DEFAULT_PATH, 1);
	if (ft_getenv("PWD") == NULL)
	{
		getcwd(pwd, SIZE_10B);
		ft_setenv("PWD", pwd, 1);
	}
	gc_free((void **)&tmp_path);
	gc_free((void **)&shell_path);
	gc_free((void **)&shlvl_value);
}

/* Save environment in accessible memory */
int	init_shell_env(char *shell_name, t_env env)
{	
	int		i;
	int		len;
	t_env	tmp;
	t_env	*shell_env;

	i = 0;
	len = env_len(env);
	shell_env = get_shell_env();
	if (*shell_env == NULL)
	{
		tmp = gc_malloc(sizeof(char *) * (len + 1));
		while (env[i])
		{
			tmp[i] = ft_strdup(env[i]);
			i++;
		}
		tmp[i] = NULL;
		*shell_env = tmp;
	}
	init_env_var(shell_name);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/10 21:59:38 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_len_var_name(char *arg)
{
	int	len;

	len = 0;
	while (arg[len] != '+' && arg[len] != '=' && arg[len] != '\0')
		++len;
	return (len);
}

static char	*get_var_name(char	*arg)
{
	int		i;
	int		j;
	char	*var_name;

	i = 0;
	j = 0;
	if (ft_isalpha(arg[i]) == 0)
		return (NULL);
	var_name = gc_malloc(sizeof(*var_name) * (get_len_var_name(arg) + 1));
	while (arg[i] != '+' && arg[i] != '=' && arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0)
		{
			gc_free((void **)&var_name);
			return (NULL);
		}
		else
			var_name[j++] = arg[i];
		++i;
	}
	var_name[i] = '\0';
	if (arg[i] == '+' && arg[i + 1] != '=')
		gc_free((void **)&var_name);
	return (var_name);
}

static char	*get_var_value(char *str, char *env_value)
{
	char	*var_value;
	char	*without_quotes;

	without_quotes = remove_quotes(str);
	if (str[-2] == '+')
		var_value = ft_strjoin(env_value, without_quotes, "");
	else
		var_value = ft_strdup(without_quotes);
	gc_free((void **)&without_quotes);
	return (var_value);
}

static void	add_to_env(char *export, char *var_name)
{
	char	*ptr;
	bool	overwrite;
	char	*env_value;
	char	*var_value;

	overwrite = true;
	var_value = NULL;
	ptr = ft_strchr(export, '=');
	env_value = ft_getenv(var_name);
	if (ptr == NULL)
	{
		var_value = NULL;
		if (env_value != NULL && env_value[-1] == '=')
			overwrite = false;
	}
	else
		var_value = get_var_value(ptr + 1, env_value);
	if (overwrite == true)
		ft_setenv(var_name, var_value, 1);
	gc_free((void **)&var_value);
}

int	export(int argc, char **argv)
{
	int		i;
	char	*var_name;

	if (argc <= 1)
		return (display_env());
	i = 1;
	while (argv[i] != NULL)
	{
		var_name = NULL;
		var_name = get_var_name(argv[i]);
		if (var_name == NULL)
		{
			ft_dprintf(STDOUT_FILENO,
				"minishell: export: `%s': not a valid identifier\n", argv[i]);
			return (EXIT_FAILURE);
		}
		add_to_env(argv[i], var_name);
		gc_free((void **)&var_name);
		++i;
	}
	return (EXIT_SUCCESS);
}

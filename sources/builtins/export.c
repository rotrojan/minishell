/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/17 01:13:47 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	display_env(void)
{
	int		i;
	t_env	*env;
	int		index_equalsign;

	i = 0;
	env = get_shell_env();
	while ((*env)[i])
	{
		ft_putstr("export ");
		if (ft_strchr((*env)[i], '=') != NULL)
		{
			index_equalsign = ft_strchr((*env)[i], '=') - (*env)[i];
			write(STDOUT_FILENO, (*env)[i], index_equalsign);
			ft_printf("=\"%s\"\n", (*env)[i] + index_equalsign + 1);
		}
		else
			ft_printf("%s\n", (*env)[i]);
		i++;
	}
	return (0);
}

static char	*export_get_var_name(char *arg)
{
	int		i;
	int		j;
	char	*var_name;

	i = 0;
	j = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (NULL);
	var_name = gc_malloc(sizeof(*var_name)
			* (export_get_len_var_name(arg) + 1));
	while (arg[i] != '+' && arg[i] != '=' && arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
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

static void	export_print_error(char const *arg, int *ret)
{
	ft_dprintf(STDERR_FILENO,
		"minishell: export: `%s': not a valid identifier\n", arg);
	*ret = EXIT_FAILURE;
}

int	export(int argc, char **argv)
{
	int		i;
	char	*var_name;
	int		ret;

	i = 0;
	if (argc <= 1)
		return (display_env());
	i = 1;
	ret = EXIT_SUCCESS;
	while (argv[i] != NULL)
	{
		var_name = NULL;
		var_name = export_get_var_name(argv[i]);
		if (var_name == NULL)
			export_print_error(argv[i], &ret);
		else
		{
			add_to_env(argv[i], var_name);
			gc_free((void **)&var_name);
		}
		++i;
	}
	return (ret);
}

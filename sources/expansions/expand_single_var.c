/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/12 16:30:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_len_var_name(char *arg)
{
	int	len;

	len = 0;
	while (ft_isalnum(arg[len]) != 0 && arg[len] != '\0')
		++len;
	return (len);
}

static char	*get_var_name(char *arg, int i)
{
	int		j;
	char	*var_name;

	j = 0;
	++i;
	var_name = gc_malloc(sizeof(*var_name) * (get_len_var_name(arg + i) + 1));
	while (ft_isalnum(arg[i]) != 0 && arg[i] != '\0')
	{
		var_name[j] = arg[i];
		++i;
		++j;
	}
	var_name[j] = '\0';
	return (var_name);
}

char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value)
{
	int		j;
	int		k;
	int		len_var_value;
	char	*new_arg;

	j = 0;
	len_var_value = ft_strlen(var_value);
	new_arg = gc_malloc(sizeof(*new_arg)
			* (ft_strlen(*arg) - len_var_name + len_var_value));
	while (j < i)
	{
		new_arg[j] = (*arg)[j];
		++j;
	}
	k = 0;
	while (var_value[k])
	{
		new_arg[j++] = var_value[k++];
	}
	i = i + len_var_name + 1;
	while ((*arg)[i] != '\0')
		new_arg[j++] = (*arg)[i++];
	gc_free((void **)arg);
	return (new_arg);
}

void	expand_single_var(
		t_simple_cmd *cmd, int *i, int *j, bool in_dquotes)
{
	char	*var_name;
	char	*var_value;

	var_name = get_var_name(cmd->argv[*i], *j);
	var_value = ft_getenv(var_name);
	if (var_value == NULL)
		var_value = "";
	if (in_dquotes == false && var_value != NULL && *var_value != '\0')
		realloc_argv(cmd, i, j, var_value);
	else
	{
		cmd->argv[*i]
			= fill_new_arg(&cmd->argv[*i], ft_strlen(var_name), *j, var_value);
		*j += ft_strlen(var_value);
	}
	gc_free((void **)&var_name);
}

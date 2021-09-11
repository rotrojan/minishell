/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:36:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/11 20:23:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		gc_free((void **)&(*array)[i]);
		++i;
	}
}

int	get_len_array(char	**array)
{
	int	len;

	len = 0;
	while (array[len] != NULL)
		++len;
	return (len);
}

char	*get_after_var(char *str, int *j)
{
	char	*ptr;
	ptr = str + *j + 1;
	while (ft_isalnum(*ptr) == 1)
		++ptr;
	return (ptr);
}

void	realloc_argv(
		t_simple_cmd *cmd, int *i, int *j, char *var_value)
{
	t_len	len;
	char	**new_argv;
	char	**splitted_var;
	t_join	join;
	int		i_old;
	int		i_new;
	int		i_split;
	char	*before_dollar;;

	splitted_var = ft_split(var_value, ' ');
	len.old_argv = get_len_array(cmd->argv);
	len.argv_to_add = get_len_array(splitted_var);
	join.first = (ft_isspace(var_value[0]) == 0);
	join.last = (ft_isspace(var_value[ft_strlen(var_value) - 1]) == 0);

	len.new_argv = len.old_argv + len.argv_to_add - 1
		+ (join.first == true) + (join.last == true);
	printf("len = %d\n", len.new_argv);
	new_argv = gc_malloc(sizeof(*new_argv) * (len.new_argv + 1));
	i_old = 0;
	i_new = 0;
	i_split = 0;
	while (i_new < *i)
		new_argv[i_new++] = ft_strdup(cmd->argv[i_old++]);
	if (join.first == true)
	{
		before_dollar = ft_strndup(cmd->argv[*i], *j);
		new_argv[i_new] = ft_strjoin(before_dollar, splitted_var[i_split], "");
		++i_new;
		++i_split;
		gc_free((void **)&before_dollar);
	}
	while (i_split < len.argv_to_add)
		new_argv[i_new++] = ft_strdup(splitted_var[i_split++]);
	if (join.last == true)
	{
		new_argv[i_new]
			= ft_strjoin(splitted_var[i_split], get_after_var(cmd->argv[*i], j), "");
		++i_new;
		++i_split;
	}
	++i_old;
	while (i_new < len.new_argv)
		new_argv[i_new++] = ft_strdup(cmd->argv[i_old++]);
	/* fill_begin_new_argv(cmd->argv, new_argv, *i); */
	free_array(&cmd->argv);
	free_array(&splitted_var);
	gc_free((void **)&splitted_var);
	cmd->argv = new_argv;
}

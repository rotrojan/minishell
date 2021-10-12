/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:36:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/12 16:28:20 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_first_join(
		char *arg, char **new_argv, char **splitted_var, t_expand_utils *utils)
{
	char	*before_dollar;

	before_dollar = ft_strndup(arg, utils->index_dollar);
	if (utils->first_join == true)
	{
		new_argv[utils->i_new]
			= ft_strjoin(before_dollar, splitted_var[utils->i_split], "");
		++utils->i_new;
		++utils->i_split;
		gc_free((void **)&before_dollar);
	}
	else if (*before_dollar != '\0')
	{
		new_argv[utils->i_new] = before_dollar;
		++utils->i_new;
	}
	else
		gc_free((void **)&before_dollar);
}

static void	init_expand_utils(char **argv, char **splitted_var, char *var_value,
		t_expand_utils *utils)
{
	utils->has_space = has_space(var_value);
	utils->first_join = (ft_isspace(var_value[0]) == 0);
	utils->last_join = (ft_isspace(var_value[ft_strlen(var_value) - 1]) == 0);
	utils->len_old_argv = get_len_array(argv);
	utils->len_argv_to_add = get_len_array(splitted_var);
	utils->len_new_argv = utils->len_old_argv + utils->len_argv_to_add
		- (utils->first_join == false) - (utils->last_join == false)
		+ (utils->has_space == true);
	utils->i_old = 0;
	utils->i_new = 0;
	utils->i_split = 0;
}

static void	handle_last_join(
		char *arg, char **new_argv, char **splitted_var, t_expand_utils *utils)
{
	char	*after_var;

	after_var = get_after_var(arg, utils->index_dollar);
	if (utils->last_join == true && *after_var != '\0')
	{
		gc_free((void **)&new_argv[utils->i_new - 1]);
		new_argv[utils->i_new - 1]
			= ft_strjoin(splitted_var[utils->i_split - 1], after_var, "");
		++utils->i_split;
	}
	else if (*after_var != '\0')
		new_argv[utils->i_new++] = ft_strdup(after_var);
}

bool	check_if_expansion_is_valid(int i, char ***splitted_var, char **argv)
{
	if (i > 0 && get_len_array(*splitted_var) > 1
		&& arg_is_redirection(argv[i - 1]) == true)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: ambiguous redirect\n", argv[i]);
		gc_free((void **)splitted_var);
		return (false);
	}
	return (true);
}

bool	realloc_argv(
		t_simple_cmd *cmd, int const i, int *j, char *var_value)
{
	t_expand_utils	utils;
	char			**new_argv;
	char			**splitted_var;

	splitted_var = ft_split(var_value, ' ');
	if (check_if_expansion_is_valid(i, &splitted_var, cmd->argv) == false)
		return (false);
	init_expand_utils(cmd->argv, splitted_var, var_value, &utils);
	utils.index_dollar = *j;
	new_argv = gc_malloc(sizeof(*new_argv) * (utils.len_new_argv + 1));
	while (utils.i_new < i)
		new_argv[utils.i_new++] = ft_strdup(cmd->argv[utils.i_old++]);
	handle_first_join(cmd->argv[i], new_argv, splitted_var, &utils);
	while (utils.i_split < utils.len_argv_to_add)
		new_argv[utils.i_new++] = ft_strdup(splitted_var[utils.i_split++]);
	handle_last_join(cmd->argv[i], new_argv, splitted_var, &utils);
	++utils.i_old;
	while (cmd->argv[utils.i_old] != NULL)
		new_argv[utils.i_new++] = ft_strdup(cmd->argv[utils.i_old++]);
	new_argv[utils.i_new] = NULL;
	free_array(&cmd->argv);
	free_array(&splitted_var);
	gc_free((void **)&splitted_var);
	cmd->argv = new_argv;
	return (true);
}

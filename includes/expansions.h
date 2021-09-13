/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:26:26 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/13 18:41:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H
# include "minishell.h"

typedef struct expand_utils
{
	int		len_old_argv;
	int		len_argv_to_add;
	int		len_new_argv;
	bool	first_join;
	bool	last_join;
	bool	has_space;
	int		i_old;
	int		i_new;
	int		i_split;
	int		index_dollar;
}	t_expand_utils;

typedef struct s_flags
{
}	t_flags;

/*
** perform_expansions.c
*/

void	perform_expansions(t_simple_cmd *cmd);

/*
** expand_single_var.c
*/

void	expand_single_var(
			t_simple_cmd *cmd, int i, int *j, bool in_dquotes);
char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value);

/*
** remove_quotes.c
*/

char	*remove_quotes(char *str);
void	remove_quotes_from_arg(char **arg);

/*
** realloc_argv.c
*/

void	realloc_argv(
			t_simple_cmd *cmd, int const i, int *j, char *var_value);

/*
** expansions_utils.c
*/

void	change_quote_state(char quote, bool *in_squotes, bool *in_dquotes);
void	free_array(char ***array);
int		get_len_array(char	**array);
char	*get_after_var(char *str, int index_dollar);
bool	has_space(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:26:26 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/21 22:22:33 by rotrojan         ###   ########.fr       */
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

/*
** perform_expansions.c
*/

bool	perform_expansions(t_simple_cmd *cmd);

/*
** fill_new_arg.c
*/

char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value);

/*
** remove_quotes.c
*/

char	*remove_quotes(char *str);
void	remove_quotes_from_arg(char **arg);

/*
** realloc_argv.c
*/

void	realloc_argv(t_simple_cmd *cmd, int const i, int *j, char *var_value);

/*
** expansions_utils.c
*/

void	change_quote_state(char quote, bool *in_squotes, bool *in_dquotes);
char	*get_after_var(char *str, int index_dollar);
int		get_len_var_name(char *arg);
char	*get_var_name(char *arg);

/*
** utils.c
*/

void	free_array(char ***array);
int		get_len_array(char	**array);
bool	has_space(char *str);


/*
** expand_vars.c
*/

bool	expand_single_var_in_stream(char **arg, int *i, bool in_dquotes);
bool	expand_vars_in_stream(char **arg);
void	expand_single_var(
		t_simple_cmd *cmd, int const i, int *j, bool in_dquotes);
void	expand_vars(t_simple_cmd *cmd, int const i);
#endif

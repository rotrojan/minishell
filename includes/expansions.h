/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:26:26 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:10 by bigo             ###   ########.fr       */
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

bool	perform_expansions(t_node *ast);

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

bool	check_if_expansion_is_valid(int i, char ***splitted_var, char **argv);
bool	realloc_argv(t_simple_cmd *cmd, int const i, int *j, char *var_value);

/*
** expansions_utils.c
*/

char	*reverse_quotes(char *var_value);
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
bool	check_for_unquoted_char(char c, char const *arg);

/*
** expand_vars.c
*/

void	expand_vars_in_stream(char **arg);
bool	expand_single_var(
			t_simple_cmd *cmd, int const i, int *j, bool in_dquotes);
bool	expand_vars(t_simple_cmd *cmd, int const i);

/*
** escape_quotes.c
*/

void	escape_quotes(char **splitted_var);
int		get_len_with_escaped_quotes(char *str);

/*
** wildcards/wildcard.c
*/

char	**wildcard(char *pathfile);

/*
** wildcards/expand_wildcard.c
*/

bool	expand_wildcard(t_simple_cmd *cmd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:26:26 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/11 19:43:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H
# include "minishell.h"

typedef struct s_len
{
	int	old_argv;
	int	argv_to_add;
	int	new_argv;
}	t_len;

typedef struct s_join
{
	bool	first;
	bool	last;
}	t_join;

/*
** perform_expansions.c
*/

void	perform_expansions(t_simple_cmd *cmd);

/*
** expand_single_var.c
*/

void	expand_single_var(
		t_simple_cmd *cmd, int *i, int *j, bool in_dquotes);
char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value);

/*
** remove_quotes.c
*/

char	*remove_quotes(char *str);

/*
** realloc_argv.c
*/

void	realloc_argv(
		t_simple_cmd *cmd, int *i, int *j, char *var_value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:26:26 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/10 22:02:48 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H
# include "minishell.h"

/*
** perform_expansions.c
*/

void	perform_expansions(t_simple_cmd *cmd);

/*
** expand_vars.c
*/

void	expand_vars(char **arg);

/*
** remove_quotes.c
*/

char	*remove_quotes(char *str);

#endif

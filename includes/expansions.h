/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:26:26 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/09 22:02:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** perform_expansions.c
*/

void	perform_expansions(t_simple_cmd *cmd);

/*
** expand_vars.c
*/

void	expand_vars(char **arg);

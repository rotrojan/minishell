/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:03:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/20 17:39:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H
# include "minishell.h"

# define CMD_NOT_FOUND_STR "%s %s: command not found"
# define BAD_SUBSTITUTION_STR "%s %s: bad substitution"
# define UNEXPECTED_TOKEN_STR "%s syntax error near unexpected token `%s'"

enum e_error
{
	NO_ERROR,
	CMD_NOT_FOUND,
	BAD_SUBSTITUTION,
	UNEXPECTED_TOKEN
};

void	display_error(enum e_error error, t_node **ast, t_token **tok_lst);

#endif

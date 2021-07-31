/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:03:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/31 20:41:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H
# include "minishell.h"

# define CMD_NOT_FOUND_STR "%s %s: command not found"
# define BAD_SUBSTITUTION_STR "%s %s: bad substitution"
# define UNEXPECTED_TOKEN_STR "%s syntax error near unexpected token `%s'"
# define UNEXPECTED_EOF_STR "%s syntax error: `%s'"
# define AMP_TOKEN_STR "%s the `%s' token is not handled by minishell"

enum e_error
{
	No_error,
	Cmd_not_found,
	Bad_substitution,
	Unexpected_token,
	Unexpected_eof,
	Amp_token
};

void	display_error(enum e_error error, t_token **tok_lst);

#endif

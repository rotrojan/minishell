/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:03:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/03 22:55:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H
# include "minishell.h"

# define CMD_NOT_FOUND_STR "%s %s: command not found"
# define BAD_SUBSTITUTION_STR "%s %s: bad substitution"
# define UNEXPECTED_TOKEN_STR "%s syntax error near unexpected token `%s'"
# define UNEXPECTED_EOF_STR "%s syntax error: unexpected end of file"
# define AMP_TOKEN_STR "%s the `&' operator is not handled by minishell"

void	display_error(t_error error, t_token **tok_lst);

#endif

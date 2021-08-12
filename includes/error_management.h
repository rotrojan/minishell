/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:03:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/12 19:01:00 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H
# include "minishell.h"

/*
** All the error messages displayed by display_error().
*/

# define CMD_NOT_FOUND_STR "%s %s: command not found\n"
# define BAD_SUBSTITUTION_STR "%s %s: bad substitution\n"
# define UNEXPECTED_TOKEN_STR "%s syntax error near unexpected token `%s'\n"
# define UNEXPECTED_EOF_STR "%s syntax error: unexpected end of file\n"
# define AMP_TOKEN_STR "%s the `&' operator is not handled by minishell\n"

void	display_error(t_error error, t_token **tok_lst);

#endif

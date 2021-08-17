/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:00:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/12 19:00:13 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Display the proper error message depending on the error variable given as
** parameter and on the next coming token where the syntac error has been
** raised.
*/

void	display_error(t_error error, t_token **tok_lst)
{
	char const	*error_msg[NB_ERRORS] = {
		NULL,
		CMD_NOT_FOUND_STR,
		BAD_SUBSTITUTION_STR,
		UNEXPECTED_TOKEN_STR,
		UNEXPECTED_EOF_STR,
		AMP_TOKEN_STR,
	};

	if (error == Unexpected_eof)
		ft_fprintf(STDERR_FILENO, error_msg[error], "\nminishell:");
	else
	{
		if (*tok_lst)
			ft_fprintf(STDERR_FILENO, error_msg[error],
				"\nminishell:", (*tok_lst)->data);
		else
			ft_fprintf(STDERR_FILENO, error_msg[error],
				"\nminishell:", "newline");
	}
}
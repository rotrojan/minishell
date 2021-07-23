/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:00:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/23 17:51:23 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_error(enum e_error error, t_token **tok_lst)
{
	char const	*error_msg[] = {
		NULL,
		CMD_NOT_FOUND_STR,
		BAD_SUBSTITUTION_STR,
		UNEXPECTED_TOKEN_STR
	};

	if (*tok_lst)
		ft_fprintf(STDERR_FILENO, error_msg[error],
			"\nminishell:", (*tok_lst)->data);
	else
		ft_fprintf(STDERR_FILENO, error_msg[error],
			"\nminishell:", "newline");
}

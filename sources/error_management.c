/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:00:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/14 16:30:32 by rotrojan         ###   ########.fr       */
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

	ft_fprintf(STDERR_FILENO, error_msg[error], "minishell:", (*tok_lst)->data);
	clear_tokens(tok_lst);
}

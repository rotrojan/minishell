/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:32:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/16 21:13:48 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Set terminal in no canonical and without echo mode. */
void	init_term(void)
{
	int		ret;
	char	*term_env;

	term_env = ft_getenv("TERM");
	if (term_env == NULL)
		gc_exit(EXIT_FAILURE, "ft_getenv(): TERM not set in env.\n");
	ret = tgetent(NULL, term_env);
	if (ret < 1)
		gc_exit(EXIT_FAILURE, "tgetent(): missing data for this term.\n");
	if (!isatty(STDIN_FILENO))
		gc_exit(EXIT_FAILURE, "isatty(): not a terminal.\n");
}

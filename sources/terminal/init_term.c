/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:32:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/13 19:08:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_term(void)
{
	int		ret;
	int		tty;
	char	*line;
	char	*term_env;

	line = NULL;
	tty = ttyslot();
	term_env = ft_getenv("TERM");
	if (term_env == NULL)
		gc_exit(EXIT_FAILURE, "ft_getenv(): TERM not set in env.\n");
	ret = tgetent(NULL, term_env);
	if (ret < 1)
		gc_exit(EXIT_FAILURE, "tgetent(): missing data for this term.\n");
	if (isatty(tty) == 0)
		return (true);
	return (false);
}

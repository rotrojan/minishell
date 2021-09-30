/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:32:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/30 00:15:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_term(void)
{
	int		ret;
	char	*line;
	char	*term_env;

	line = NULL;
	term_env = ft_getenv("TERM");
	if (term_env == NULL)
	{
		ft_setenv("TERM", DEFAULT_TERM, 1);
		term_env = ft_getenv("TERM");
	}
	ret = tgetent(NULL, term_env);
	if (ret < 1)
		gc_exit(EXIT_FAILURE, "tgetent(): missing data for this term.\n");
	if (isatty(STDIN_FILENO) == 0)
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:32:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 16:47:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_term(void)
{
	int		ret;
	char	*term_env;
	t_term	*term;

	term = getterm();
	term_env = getenv("TERM");
	if (term_env == NULL)
		gc_exit(EXIT_FAILURE, "getenv(): TERM not set in env.\n");
	ret = tgetent(NULL, term_env);
	if (ret < 1)
		gc_exit(EXIT_FAILURE, "tgetent(): missing data for this term.\n");
	if (!isatty(STDIN_FILENO))
		gc_exit(EXIT_FAILURE, "isatty(): not a terminal.\n");
	tcgetattr(STDIN_FILENO, &term->old);
	term->current = term->old;
	term->current.c_lflag &= ~(ICANON | ECHO);
	term->current.c_cc[VMIN] = 1;
	term->current.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->current);
}

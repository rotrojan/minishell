/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/04 19:41:22 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_term	init_term(void)
{
	int		ret;
	char	*term_env;
	t_term	term;

	term_env = getenv("TERM");
	if (term_env == NULL)
		gc_exit(EXIT_FAILURE, "getenv(): TERM not set in env.");
	ret = tgetent(NULL, term_env);
	if (ret < 1)
		gc_exit(EXIT_FAILURE, "tgetent(): missing data for this term");
	if (!isatty(STDIN_FILENO))
		gc_exit(EXIT_FAILURE, "isatty(): not a terminal.");
	tcgetattr(STDIN_FILENO, &term.old);
	term.current = term.old;
	term.current.c_lflag &= ~(ICANON | ECHO);
	term.current.c_cc[VMIN] = 1;
	term.current.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term.current);
	return (term);
}

int	main(int argc, char **argv, char **env)
{
	t_term	term;

	(void)argc;
	(void)argv;
	(void)env;
	term = init_term();
	handle_signals();
	shell();
	tcsetattr(STDIN_FILENO, TCSANOW, &term.old);
	gc_exit(EXIT_SUCCESS, "");
	return (EXIT_SUCCESS);
}

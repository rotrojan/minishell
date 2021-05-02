/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/02 19:53:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_term(void)
{
	int		ret;
	char	*term_env;
	// t_term	term;

	term_env = getenv("TERM");
	if (term_env == NULL)
		ft_exit(EXIT_FAILURE, "getenv(): TERM not set in env.");
	ret = tgetent(NULL, term_env);
	if (ret < 1)
		ft_exit(EXIT_FAILURE, "tgetent(): missing data for this term");
	// return (term);
}

int	main(int argc, char **argv, char **env)
{
	// t_term	term;

	(void)argc;
	(void)argv;
	(void)env;
	init_term();
	shell();
	return (EXIT_SUCCESS);
}

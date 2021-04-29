/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/29 22:52:26 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_error(char *error)
{
	ft_fputstr(STDERR_FILENO, error);
	exit(EXIT_FAILURE);
}

static void	ft_init_term(void)
{
	int		ret;
	char	*term;

	term = getenv("TERM");
	if (term == NULL)
		ft_exit_error("getenv(): TERM not set in env.\n");
	ret = tgetent(NULL, term);
	if (ret < 1)
		ft_exit_error("tgetent(): missing or insufficient data for this term\n");
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	ft_init_term();
	return (EXIT_SUCCESS);
}

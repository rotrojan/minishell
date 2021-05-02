/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/02 18:53:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_term(void)
{
	int		ret;
	char	*term;

	term = getenv("TERM");
	if (term == NULL)
		exit_error("getenv(): TERM not set in env.\n");
	ret = tgetent(NULL, term);
	if (ret < 1)
		exit_error("tgetent(): missing or insufficient data for this term\n");
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	ft_init_term();
	ft_shell();
	return (EXIT_SUCCESS);
}

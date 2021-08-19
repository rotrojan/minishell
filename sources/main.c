/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/19 18:50:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_leaks(void) __attribute__((destructor));

static void	free_leaks(void)
{
	gc_free_all();
}

/* Init and launch all process. */
int	main(int argc, char **argv, char **env)
{
	(void)(argc && argv);
	init_shell_env(env);
	init_term();
	handle_signals();
	init_history();
	shell();
	return (EXIT_FAILURE);
}

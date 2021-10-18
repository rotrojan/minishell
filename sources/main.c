/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/18 22:41:20 by lucocozz         ###   ########.fr       */
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
	bool	inline_mode;

	(void)argc;
	init_shell_env(extract_file(argv[0]), env);
	inline_mode = init_term();
	init_history();
	shell(inline_mode);
	return (EXIT_FAILURE);
}

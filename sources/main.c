/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/24 23:45:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Init and launch all process. */
int	main(int argc, char **argv, char **env)
{
	(void)(argc && argv);
	init_shell_env(env);
	init_term();
	handle_signals();
	init_history();
	shell();
	exit_shell(EXIT_SUCCESS, "\n");
	return (EXIT_SUCCESS);
}

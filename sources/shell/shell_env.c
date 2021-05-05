/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:00:52 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 22:58:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_shell_env(void)
{
	static t_env	shell_env = NULL;

	return (&shell_env);
}

void	init_shell_env(t_env *env)
{
	t_env	*shell_env;

	shell_env = get_shell_env();
	if (*shell_env == NULL)
		*shell_env = *env;
}

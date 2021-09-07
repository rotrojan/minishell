/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:58:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/17 18:47:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Unset VAR in environment.
Return 1 if exist, if not return 0. */
int	ft_unsetenv(const char *name)
{
	int		i;
	int		ret;
	t_env	new;
	t_env	*env;

	i = 0;
	env = get_shell_env();
	ret = ft_inenv(name);
	if (ret == -1)
		return (0);
	new = gc_malloc(sizeof(char *) * env_len(*env));
	while ((*env)[i])
	{
		if (i == ret)
			gc_free((void **)&(*env)[i]);
		else if (i >= ret)
			new[i - 1] = (*env)[i];
		else
			new[i] = (*env)[i];
		i++;
	}
	new[i - 1] = NULL;
	gc_free((void **)&*env);
	*env = new;
	return (1);
}

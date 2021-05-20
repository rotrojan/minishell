/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:58:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/20 19:10:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unsetenv(const char *name)
{
	int		i;
	int		ret;
	t_env	tmp;
	t_env	new;
	t_env	*env;

	i = 0;
	env = get_shell_env();
	tmp = *env;
	ret = ft_inenv(name);
	if (ret == -1)
		return (0);
	new = gc_alloc(sizeof(char *) * env_len(*env));
	while (tmp[i])
	{
		if (i == ret)
			gc_free(tmp[i]);
		else
			new[i] = tmp[i];
		i++;
	}
	new[i] = NULL;
	*env = new;
	gc_free(tmp);
	return (1);
}

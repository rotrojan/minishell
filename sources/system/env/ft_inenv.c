/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:04:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/24 16:17:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return index of VAR in environment,
return -1 if not found. */
int	ft_inenv(const char *name)
{
	int		i;
	int		len;
	char	*var;
	t_env	*env;
	t_env	tmp;

	i = 0;
	var = ft_strjoin(name, "=", "");
	len = ft_strlen(var);
	env = get_shell_env();
	tmp = *env;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], var, len) == 0)
		{
			gc_free(var);
			return (i);
		}
		i++;
	}
	gc_free(var);
	return (-1);
}

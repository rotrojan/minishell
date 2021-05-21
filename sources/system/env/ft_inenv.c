/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:04:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 13:36:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Return index of VAR in environment,
return -1 if not found. */
int	ft_inenv(const char *name)
{
	int		i;
	int		len;
	t_env	*env;
	t_env	tmp;

	i = 0;
	len = ft_strlen(name);
	env = get_shell_env();
	tmp = *env;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], name, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:57:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/20 21:02:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name)
{
	int		i;
	t_env	tmp;
	t_env	*env;

	i = ft_inenv(name);
	if (i == -1)
		return (NULL);
	env = get_shell_env();
	tmp = *env;
	return (&tmp[i][ft_strlen(name) + 1]);
}

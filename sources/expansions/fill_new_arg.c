/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/26 15:58:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*alloc_new_arg(char *arg, int len_var_name, char *var_value)
{
	char	*new_arg;
	int		len_var_value;

	len_var_value = ft_strlen(var_value);
	new_arg = gc_malloc(sizeof(*new_arg)
			* (ft_strlen(arg) - len_var_name + len_var_value));
	return (new_arg);
}

char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value)
{
	int		j;
	int		k;
	char	*new_arg;

	j = 0;
	new_arg = alloc_new_arg(*arg, len_var_name, var_value);
	while (j < i)
	{
		new_arg[j] = (*arg)[j];
		++j;
	}
	k = 0;
	while (var_value[k])
		new_arg[j++] = var_value[k++];
	i = i + len_var_name + 1;
	while ((*arg)[i] != '\0')
		new_arg[j++] = (*arg)[i++];
	new_arg[j] = '\0';
	gc_free((void **)arg);
	return (new_arg);
}

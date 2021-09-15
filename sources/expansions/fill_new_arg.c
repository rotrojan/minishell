/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/15 23:07:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	get_proper_quote(char *arg)
{
	while (*arg != '\0')
	{
		if (*arg == '\'')
			return ('"');
		else if (*arg == '"')
			return ('\'');
		++arg;
	}
	return ('"');
}

char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value)
{
	int		j;
	int		k;
	int		len_var_value;
	char	*new_arg;
	char	quote;

	j = 0;
	quote = get_proper_quote(*arg);
	len_var_value = ft_strlen(var_value);
	new_arg = gc_malloc(sizeof(*new_arg)
			* (ft_strlen(*arg) - len_var_name + len_var_value + 2));
	new_arg[j++] = quote;
	while (j <= i)
	{
		new_arg[j] = (*arg)[j - 1];
		++j;
	}
	k = 0;
	while (var_value[k])
		new_arg[j++] = var_value[k++];
	i = i + len_var_name + 1;
	while ((*arg)[i] != '\0')
		new_arg[j++] = (*arg)[i++];
	new_arg[j++] = quote;
	new_arg[j++] = '\0';
	gc_free((void **)arg);
	return (new_arg);
}

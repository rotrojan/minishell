/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo </var/spool/mail/bigo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:57:42 by bigo              #+#    #+#             */
/*   Updated: 2021/10/17 01:09:54 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_get_len_var_name(char *arg)
{
	int	len;

	len = 0;
	while (arg[len] != '+' && arg[len] != '=' && arg[len] != '\0')
		++len;
	return (len);
}

char	*get_var_value(char *str, char *env_value)
{
	char	*var_value;

	if (*(str - 2) == '+')
		var_value = ft_strjoin(env_value, str, "");
	else
		var_value = ft_strdup(str);
	return (var_value);
}

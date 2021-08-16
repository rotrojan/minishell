/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/16 20:34:25 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_var(char const *str)
{
	bool			in_squotes;
	bool			in_dquotes;
	unsigned int	i;

	in_squotes = FALSE;
	in_dquotes = FALSE;
	while (str[i] != '\0')
	{
		if (str[i] == ''')
			in_squotes = (in_squotes == FALSE);
		else if (str[i] == '"')
			in_dquotes = (in_dquotes == FALSE);
		else if (str[i] == '$')
		{
			
		}

	}
	ft_get_env(var_name);
}

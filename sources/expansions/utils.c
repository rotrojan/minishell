/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:02:02 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/06 18:09:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		gc_free((void **)&(*array)[i]);
		++i;
	}
}

int	get_len_array(char	**array)
{
	int	len;

	len = 0;
	while (array[len] != NULL)
		++len;
	return (len);
}

bool	has_space(char *str)
{
	while (*str != '\0')
		if (ft_isspace(*(str++)))
			return (true);
	return (false);
}

bool	check_for_unquoted_char(char c, char const *arg)
{
	bool	in_squotes;
	bool	in_dquotes;

	in_squotes = false;
	in_dquotes = false;
	while (*arg != '\0')
	{
		if (*arg == '\'' && in_dquotes == true)
			in_squotes = (in_squotes == false);
		else if (*arg == '"' && in_squotes == true)
			in_dquotes = (in_dquotes == false);
		else if (*arg == c && in_squotes == false && in_dquotes == false)
			return (true);
		++arg;
	}
	return (false);
}

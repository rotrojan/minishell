/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:31:27 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/14 20:49:49 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_identifier(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: unset: `%s': not a valid identifier\n", arg);
		return (EXIT_FAILURE);
	}
	while (arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: unset: `%s': not a valid identifier\n", arg);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	unset(int argc, char **argv)
{
	int	i;
	int	ret;

	(void)argc;
	i = 0;
	ret = EXIT_SUCCESS;
	while (argv[i] != NULL)
	{
		if (check_identifier(argv[i]) == EXIT_FAILURE && ret == EXIT_SUCCESS)
			ret = EXIT_FAILURE;
		ft_unsetenv(argv[i]);
		++i;
	}
	return (ret);
}

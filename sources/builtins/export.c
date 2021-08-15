/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 19:15:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export(int argc, char **argv)
{
	int		i;
	int		j;
	char	*var_name;

	if (argc <= 1)
		return (ft_env(argc, argv));
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0' && argv[i][j] != '=')
			++j;
		if (argv[i][j] != '=')
			return (ft_env(argc, argv));
		var_name = ft_strndup(argv[i], j);
		ft_setenv(var_name, &argv[i][++j], 1);
		gc_free(var_name);
		++i;
	}
	return (0);
}

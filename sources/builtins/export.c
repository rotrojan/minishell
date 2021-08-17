/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/17 20:55:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	lex_arg(char *arg)
{
	unsigned int	i;
	bool			in_squotes;
	bool			in_dquotes;

	i = 0;
	in_squotes = FALSE;
	in_dquotes = FALSE;
	if (ft_isalpha(arg[i]) == FALSE)
		return (FALSE);
	++i;
	while (arg[i] != NULL
		&& (ft_isalpha(arg[i]) == TRUE || ft_isdigit(arg[i] == TRUE)))
		++i;
	if (!(arg[i] == '=' && (arg[i] == '+' && arg[i + 1] == '=')))

}

static bool	export_arg(char	*arg)
{
	unsigned int	i;
	bool			in_squotes;

	if (lex_arg(arg) == NULL)
		return (FALSE);
}

int	export(int argc, char **argv)
{
	int		i;

	if (argc <= 1)
		return (ft_env(argc, argv));
	i = 1;
	while (argv[i] != NULL)
	{
		if (export_arg(argv[i]) == FALSE)
		{
			ft_fprintf(STDOUT_FILENO,
				"minishell: export: `%s': not a valid identifier\n", argv[i]);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

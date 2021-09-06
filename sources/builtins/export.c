/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:44:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/06 19:15:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	/* bool			in_squotes; */
	/* bool			in_dquotes; */

	/* i = 0; */
	/* in_squotes = FALSE; */
	/* in_dquotes = FALSE; */
	/* if (ft_isalpha(arg[i]) == FALSE) */
		/* return (FALSE); */
	/* ++i; */
	/* while (arg[i] != '\0' */
		/* && (ft_isalpha(arg[i]) == TRUE || ft_isdigit(arg[i] == TRUE))) */
		/* ++i; */
	/* [> if (!(arg[i] == '=' && (arg[i] == '+' && arg[i + 1] == '='))) <] */
	/* return (TRUE); */

/* } */

static int	get_len_var_name(char *arg)
{
	int	i;
	int	len_var_name;

	i = 0;
	len_var_name = 0;
	while (arg[i] != '+' && arg[i] != '=' && arg[i] != '\0')
	{
		if (arg[i] != '\'' || arg[i] != '"')
			++len_var_name;
		++i;
	}
	return (len_var_name);
}

static char	*get_var_name(char	*arg)
{
	int		i;
	int		j;
	bool	in_squotes;
	bool	in_dquotes;
	char	*var_name;

	i = 0;
	in_squotes = FALSE;
	in_dquotes = FALSE;
	if (arg[i] == '\'')
	{
		in_squotes = TRUE;
		++i;
	}
	else if (arg[i] == '"')
	{
		in_dquotes = TRUE;
		++i;
	}
	if (ft_isalpha(arg[i]) == 0)
		return (NULL);
	++i;
	j = 0;
	var_name = malloc(sizeof(*var_name) * (get_len_var_name(arg) + 1));
	while (arg[i] != '+' && arg[i] != '=' && arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0)
		{
			if (arg[i] == '\"')
			{
				if (in_squotes == TRUE)
					in_squotes = FALSE;
				else if (in_squotes == FALSE || in_dquotes == FALSE)
					in_squotes = TRUE;
			}
			else if (arg[i] == '"')
			{
				if (in_dquotes == TRUE)
					in_dquotes = FALSE;
				else if (in_dquotes == FALSE || in_squotes == FALSE)
					in_dquotes = TRUE;
			}
			return (NULL);
		}
		else
			var_name[j++] = arg[i];

		++i;
	}
	return (var_name);
}

int	export(int argc, char **argv)
{
	int		i;
	char	*var_name;

	if (argc <= 1)
		return (ft_env(argc, argv));
	i = 1;
	while (argv[i] != NULL)
	{
		var_name = get_var_name(argv[i]);
		if (var_name == NULL)
		{
			ft_fprintf(STDOUT_FILENO,
				"minishell: export: `%s': not a valid identifier\n", argv[i]);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

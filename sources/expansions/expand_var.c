/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/08 18:12:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* char	expand_word(int *argc, char **argv) */
/* { */
	/* unsigned int	i; */
	/* unsigned int	j; */

	/* while () */
	/* { */

	/* } */
	/* return (argv); */
/* } */
static int	get_len_var_name(char *arg)
{
	int	len;

	len = 0;
	ft_printf("yolo\n");
	while (ft_isalnum(arg[len]) != 0 && arg[len] != '\0')
		++len;
	return (len);
}

static char	*get_var_name(char *arg, int *i)
{
	int		j;
	char	*var_name;

	i = 0;
	j = 0;
	printf("%s\n", &arg[*i]);
	if (ft_isalpha(arg[*i]) == 0)
		return (NULL);
	int len = get_len_var_name(arg);
	printf("len = %d\n", len);
	var_name = gc_malloc(sizeof(*var_name) * (get_len_var_name(arg) + 1));
	while (ft_isalnum(arg[*i]) != 0 && arg[*i] != '\0')
	{
		if (ft_isalnum(arg[*i]) == 0)
		{
			gc_free((void **)&var_name);
			return (NULL);
		}
		else
			var_name[j++] = arg[*i];
		++i;
	}
	var_name[*i] = '\0';
	if (arg[*i] == '+' && arg[*i + 1] != '=')
		gc_free((void **)&var_name);
	return (var_name);
}

void	expand_vars(char **arg)
{
	bool	in_squotes;
	bool	in_dquotes;
	int		i;
	char	*var_name;

	in_squotes = FALSE;
	in_dquotes = FALSE;
	i = 0;
	while (*arg[i] != '\0')
	{
		if (*arg[i] == '\'' && in_squotes == FALSE && in_dquotes == FALSE)
			in_squotes = (in_squotes == FALSE);
		else if (*arg[i] == '"' && in_squotes == FALSE && in_dquotes == FALSE)
			in_dquotes = (in_dquotes == FALSE);
		if (*arg[i] == '$')
		{
			var_name = get_var_name(*arg, &i);
			printf("%s\n", var_name);
		}
		else
			++i;
	}
	gc_free((void **)arg);
	*arg = ft_getenv(var_name);
	gc_free((void **)var_name);
}

void	perform_expansions(t_simple_cmd *cmd)
{
	char			**argv;
	int				i;
	t_redirection	*redir_lst;

	argv = cmd->argv;
	redir_lst = cmd->redirection;
	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], '$'))
			expand_vars(&argv[i]);
		/* remove_quotes() */
		++i;
	}
	while (redir_lst != NULL)
	{
		redir_lst = redir_lst->next;
	}
}

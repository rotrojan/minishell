/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/09 20:52:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fill_new_arg(char **arg, int len_var_name, int i, char *var_value)
{
	int		j;
	int		k;
	int		len_var_value;
	char	*new_arg;

	j = 0;
	len_var_value = ft_strlen(var_value);
	new_arg = gc_malloc(sizeof(*new_arg)
			* (ft_strlen(*arg) - len_var_name + len_var_value));
	while (j < i)
	{
		new_arg[j] = (*arg)[j];
		++j;
	}
	k = 0;
	while (var_value[k])
	{
		new_arg[j++] = var_value[k++];
	}
	i = i + len_var_name + 1;
	while ((*arg)[i] != '\0')
		new_arg[j++] = (*arg)[i++];
	gc_free((void **)arg);
	return (new_arg);
}

static int	get_len_var_name(char *arg)
{
	int	len;

	len = 0;
	while (ft_isalnum(arg[len]) != 0 && arg[len] != '\0')
		++len;
	return (len);
}

static char	*get_var_name(char *arg, int i)
{
	int		j;
	char	*var_name;

	j = 0;
	++i;
	var_name = gc_malloc(sizeof(*var_name) * (get_len_var_name(arg + i) + 1));
	while (ft_isalnum(arg[i]) != 0 && arg[i] != '\0')
	{
		var_name[j] = arg[i];
		++i;
		++j;
	}
	var_name[j] = '\0';
	return (var_name);
}

void	expand_vars(char **arg)
{
	int		i;
	char	*var_name;
	char	*var_value;

	i = 0;
	while (*(*arg + i) != '\0')
	{
		if (*(*arg + i) == '$')
		{
			if (*(*arg + i + 1) == '\0' || ft_isalnum(*(*arg + i + 1)) == 0)
				*arg = fill_new_arg(arg, 0, i++, "$");
			else
			{
				var_name = get_var_name(*arg, i);
				var_value = ft_getenv(var_name);
				*arg = fill_new_arg(arg, ft_strlen(var_name), i, var_value);
				i += ft_strlen(var_value);
				gc_free((void **)&var_name);
			}
		}
		else
			++i;
	}
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

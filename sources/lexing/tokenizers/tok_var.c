/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:27:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/25 19:01:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *expand_var(char *inchars, int *i, int *j, t_state *state)
{
	char	*str;
	char	*nested_var;
	char	*tmp;

	*j = 0;
	(void)state;
	nested_var = NULL;
	/* nested_var = ft_strchr(&inchars[*i], '$'); */
	/* if (nested_var != NULL) */
	/* { */
		/* while (inchars[*i + *j] != '$') */
			/* (*j)++; */
		/* str = gc_malloc(sizeof(*str) * (*j + 1)); */
		/* ft_strlcpy(str, &inchars[*i], *j + 1); */
		/* tmp = ft_strjoin(str, expand_var(&inchars[*i + *j], i, j, state), ""); */
		/* gc_free(str); */
		/* str = tmp; */
	/* } */
	/* else */
	/* { */
		while (inchars[*i + *j] != '$')
			j++;
		str = gc_malloc(sizeof(*str) * (*j + 1));
		ft_strlcpy(str, &inchars[*i], *j + 1);
	/* } */
	return (ft_getenv(str));
	 
}

t_token	*tok_var(t_token **tok_lst, char *inchars, int *i, t_state *state)
{
	t_token	*tok;
	char	*data;
	int		j;
	char	*expanded_var;

	(void)state;
	j = 0;
	data = NULL;
	tok = NULL;
	if (inchars[*i])
		(*i)++;
	else
	{
		printf("NULL\n");
		return (NULL);
	}
	/* printf("%s\n", ft_getenv("SHELL")); */
	/* while (inchars[*i + j] != '\"') */
		/* j++; */
	/* if (*state == State_general) */
		/* while (!is_sep(inchars[*i + j])) */
			/* j++; */
	/* else if (*state == State_indquote) */
	/* { */
		/* while (!is_sep(inchars[*i + j])) */
		/* { */
			/* if (inchars[*i + j] == '$') */
			/* j++; */
		/* } */
		
	/* } */
	data = gc_malloc(sizeof(*data) * (j + 1));
	while (!is_sep(inchars[*i + j]))
		j++;
	ft_strlcpy(data, &inchars[*i], j + 1);
	expanded_var = ft_getenv(data);
	gc_free(data);
	data = gc_malloc(sizeof(*data) * (ft_strlen(expanded_var) + 1));
	ft_strlcpy(data, expanded_var, (ft_strlen(expanded_var) + 1));
	create_token(data, Alnum, tok_lst);
	*i++ += j;
	return (tok);
}

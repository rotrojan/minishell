/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:09:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/25 17:43:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *data, t_type type, t_token **tok_lst)
{
	t_token	*new_tok;
	t_token	*current;

	new_tok = gc_malloc(sizeof(*new_tok));
	new_tok->data = data;
	new_tok->type = type;
	new_tok->next = NULL;
	if (*tok_lst == NULL)
		*tok_lst = new_tok;
	else
	{
		current = *tok_lst;
		while (current->next)
			current = current->next;
		current->next = new_tok;
	}
	return (new_tok);
}

void	set_tokenizer_array(
t_token *(**tokenizer_array)(t_token**, char*, int*, t_state*))
{
	int	i;

	ft_bzero(tokenizer_array, sizeof(tokenizer_array) * 128);
	i = '0';
	while (i <= '9')
		tokenizer_array[i++] = &tok_alnum;
	i = 'A';
	while (i <= 'Z')
		tokenizer_array[i++] = &tok_alnum;
	i = 'a';
	while (i <= 'z')
		tokenizer_array[i++] = &tok_alnum;
	tokenizer_array['$'] = &tok_var;
	tokenizer_array['\''] = &tok_squote;
	tokenizer_array['\"'] = &tok_dquote;
	/* tokenizer_array['|'] = &tok_pipe; */
	/* tokenizer_array['&'] = &tok_amp; */
	/* tokenizer_array['\\'] = &tok_backslash; */
	/* tokenizer_array[';'] = &tok_semic; */
	/* tokenizer_array['<'] = tok_lesser; */
	/* tokenizer_array['>'] = &tok_greater; */
	/* tokenizer_array['('] = &tok_oparent; */
	/* tokenizer_array[')'] = &tok_cparent; */
}

t_token	*lexer_build(char *inchars)
{
	t_token	*tok_lst;
	t_state	state;
	t_token	*(*tokenizer[128])(t_token**, char*, int*, t_state*);
	int		i;

	i = 0;
	state = State_general;
	set_tokenizer_array(tokenizer);
	while (inchars[i])
	{
		tokenizer[(int)inchars[i]](&tok_lst, inchars, &i, &state);
		while (ft_isspace(inchars[i]))
			i++;
	}
	return (tok_lst);
}

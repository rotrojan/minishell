/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:09:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/19 14:38:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *data, t_type type, t_token **tok_lst)
{
	t_token	*new_tok;
	t_token	*current;

	new_tok = gc_malloc(sizeof new_tok);
	if (new_tok == NULL)
		return (NULL);
	new_tok->data = gc_malloc(sizeof new_tok->data * (ft_strlen(data) + 1));
	if (new_tok->data == NULL)
		return (NULL);
	new_tok->type = type;
	new_tok->next = NULL;
	current = *tok_lst;
	while (current->next)
		current = current->next;
	current->next = new_tok;
	return (new_tok);
}

void	*set_tokenizer_array[128](void)
{
	int	i;

	if (tokenizer_array == NULL)
	{
		ft_bzero(&tokenizer_array, sizeof tokenizer_array);
		i = '0';
		while (i <= '9')
			tokenizer_array[i] = tok_alnum;
		i = 'A'
		while (i <= 'Z')
			tokenizer_array[i] = tok_alnum;
		i = 'a'
		while (i <= 'z')
			tokenizer_array[i] = tok_alnum;
		tokenizer_array['$'] = tok_var;
		tokenizer_array['\''] = tok_squote;
		tokenizer_array['\"'] = tok_dquote;
		tokenizer_array['|'] = tok_pipe;
		tokenizer_array['&'] = tok_amp;
		tokenizer_array['\\'] = tok_backslash;
		tokenizer_array[';'] = tok_semic;
		tokenizer_array['<'] = tok_lesser;
		tokenizer_array['>'] = tok_greater;
		tokenizer_array['('] = tok_oparent;
		tokenizer_array[')'] = tok_cparent;
	}
}

void *get_tokenizer_array(char inchar)
{
	static (void*)tokenizer_array[128](char) = NULL;

	if (tokenizer_array == NULL)
		tokenizer_array = set_tokenizer_array();
	return (tokenizer_array);;
}

t_token	*lexer_build(t_inchar *inchars)
{
	t_inchar	*current_inchar;
	t_token	*tok_lst;
	e_state	state;

	current_inchar = inchars;
	state = STATE_GENERAL;
	while (current_inchar)
	{
		get_token(current_inchar)
		current_inchar = current_inchar->next;
	}
	return (tok_lst);
}

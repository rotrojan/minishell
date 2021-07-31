/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:46:23 by rotroja          #+#    #+#             */
/*   Updated: 2021/07/31 18:42:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_token *new_tok, t_token **tok_lst)
{
	t_token	*current;

	if (*tok_lst == NULL)
		*tok_lst = new_tok;
	else
	{
		current = *tok_lst;
		while (current->next)
			current = current->next;
		current->next = new_tok;
	}
}

void	clear_tokens(t_token **tok_lst)
{
	t_token	*prev;
	t_token	*current;

	if (*tok_lst == NULL)
		return ;
	current = *tok_lst;
	while (current)
	{
		gc_free(current->data);
		prev = current;
		current = current->next;
		gc_free(prev);
	}
	*tok_lst = NULL;
}

t_token	*create_token(char *data, enum e_tok_type type)
{
	t_token	*new_tok;

	new_tok = gc_malloc(sizeof(*new_tok));
	new_tok->data = data;
	new_tok->type = type;
	new_tok->next = NULL;
	return (new_tok);
}

enum e_chr_type	get_chr_type(char c)
{
	enum e_chr_type const chr_type[128] = {
		Any_chr,
		['\t' ...'\r'] = Space_chr,
		[' '] = Space_chr,
		['\"'] = Dquote_chr,
		['&'] = And_chr,
		['\''] = Squote_chr,
		['('] = Oparenth_chr,
		[')'] = Cparenth_chr,
		[';'] = Semic_chr,
		['<'] = Less_chr,
		['>'] = Great_chr,
		['|'] = Pipe_chr
	};

	if (c == '\0')
		return (Null_chr);
	return (chr_type[(int)c]);
}

char	*join_chars(char *str, const char *chrs, int nb_chrs)
{
	char	*strnew;
	int		str_size;

	strnew = NULL;
	str_size = ft_strlen(str);
	strnew = gc_malloc(sizeof(*strnew) * (str_size + nb_chrs + 1));
	ft_strlcpy(strnew, str, str_size + 1);
	ft_strlcpy(strnew + str_size, chrs, nb_chrs + 1);
	gc_free(str);
	return (strnew);
}

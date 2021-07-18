/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:46:23 by rotroja          #+#    #+#             */
/*   Updated: 2021/07/18 20:32:14 by rotrojan         ###   ########.fr       */
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
	static enum e_chr_type	chr_type[128] = {[0] = Error_chr, [1] = Error_chr,
		[2] = Error_chr, [3] = Error_chr, [4] = Error_chr, [5] = Error_chr,
		[6] = Error_chr, [7] = Error_chr, [8] = Error_chr,
		['\t' ...'\r'] = Space_chr, [14] = Error_chr, [15] = Error_chr,
		[16] = Error_chr, [17] = Error_chr, [18] = Error_chr, [19] = Error_chr,
		[20] = Error_chr, [21] = Error_chr, [22] = Error_chr, [23] = Error_chr,
		[24] = Error_chr, [25] = Error_chr, [26] = Error_chr, [27] = Error_chr,
		[28] = Error_chr, [29] = Error_chr, [30] = Error_chr, [31] = Error_chr,
		[' '] = Space_chr, ['!'] = Print_chr, ['\"'] = Dquote_chr,
		['#'] = Print_chr, ['$'] = Dol_chr, ['%'] = Print_chr, ['&'] = And_chr,
		['\''] = Squote_chr, ['('] = Print_chr, [')'] = Print_chr,
		['*'] = Print_chr, ['+'] = Print_chr, [','] = Print_chr,
		['-'] = Print_chr, ['.'] = Print_chr, ['/'] = Print_chr,
		['0' ...'9'] = Digit_chr, [':'] = Print_chr, [';'] = Semic_chr,
		['<'] = Less_chr, ['='] = Print_chr, ['>'] = Great_chr,
		['?'] = Print_chr, ['@'] = Print_chr, ['A' ...'Z'] = Alpha_chr,
		['['] = Print_chr, ['\\'] = Esc_chr, [']'] = Print_chr,
		['^'] = Print_chr, ['_'] = Print_chr, ['`'] = Print_chr,
		['a' ...'z'] = Digit_chr, ['{'] = Print_chr, ['|'] = Pipe_chr,
		['}'] = Print_chr, ['~'] = Print_chr, [127] = Error_chr,
	};

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

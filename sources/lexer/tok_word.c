/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:39:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/18 20:28:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static enum e_chr_rules	word_rules(enum e_chr_type chr_type)
{
	static enum e_chr_rules	word_rules[] = {
		[Error_chr] = Not_accepted,
		[Alpha_chr] = Accepted,
		[Digit_chr] = Accepted,
		[Print_chr] = Accepted,
		[Space_chr] = Not_accepted,
		[Squote_chr] = Accepted,
		[Dquote_chr] = Accepted,
		[Dol_chr] = Accepted,
		[Less_chr] = Not_accepted,
		[Great_chr] = Not_accepted,
		[And_chr] = Not_accepted,
		[Esc_chr] = Accepted,
		[Semic_chr] = Not_accepted,
		[Pipe_chr] = Not_accepted
	};

	return (word_rules[chr_type]);
}

static enum e_chr_rules	is_valid(char c, enum e_state *state)
{
	enum e_chr_type	chr_type;

	chr_type = get_chr_type(c);
	if (*state == State_general)
	{
		if (chr_type == Squote_chr)
			*state = State_insquote;
		else if (chr_type == Dquote_chr)
			*state = State_indquote;
		else if (chr_type == Esc_chr)
			*state = State_escaped;
	}
	else
	{
		if (*state == State_escaped)
			*state = State_general;
		if (*state == State_insquote)
			if (chr_type == Squote_chr)
				*state = State_general;
		if (*state == State_indquote)
			if (chr_type == Dquote_chr)
				*state = State_general;
		return (Accepted);
	}
	return (word_rules(chr_type));
}

t_token	*tok_word(char *inchars, int *i)
{
	char				*data;
	int					j;
	enum e_chr_rules	ret;
	enum e_state		state;

	j = 0;
	/* ret = word_rules(inchars[*i]); */
	data = gc_malloc(sizeof(*data) * 1);
	*data = '\0';
	state = State_general;
	ret = is_valid(inchars[*i], &state);
	while (ret == Accepted)
	{
		++j;
		ret = is_valid(inchars[*i + j], &state);
	}
	data = join_chars(data, inchars + *i, j);
	*i += j;
	return (create_token(data, Word_tok));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/25 17:34:19 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef enum e_type
{
	Alnum,
	Var,
	Squote,
	Dquote,
	Pipe,
	Or,
	Amp,
	And,
	Backslash,
	Semic,
	Lesser,
	Dlesser,
	Greater,
	Dgreater,
	Oparent,
	Cparent
}	t_type;

typedef enum e_state
{
	State_general,
	State_var,
	State_insquote,
	State_indquote,
	State_pipe,
	State_amp,
	State_escaped,
	State_lesser,
	State_greater,
	State_inparent
}	t_state;

typedef struct s_token
{
	char			*data;
	enum e_type		type;
	struct s_token	*next;
}	t_token;

t_token	*lexer_build(char *inchars);
t_token	*create_token(char *data, t_type type, t_token **tok_lst);

t_token	*tok_alnum(t_token **tok_lst, char *inchars, int *i, t_state *state);
t_token	*tok_squote(t_token **tok_lst, char *inchars, int *i, t_state *state);
t_token	*tok_dquote(t_token **tok_lst, char *inchars, int *i, t_state *state);
t_token	*tok_var(t_token **tok_lst, char *inchars, int *i, t_state *state);

int	is_sep(char c);

#endif

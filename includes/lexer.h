/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/31 20:07:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"
# define SIZE_OF_ONE_CHAR_STR 2
# define SIZE_OF_TWO_CHAR_STR 3

enum e_chr_type
{
	Any_chr,
	Null_chr,
	Space_chr,
	Squote_chr,
	Dquote_chr,
	Less_chr,
	Great_chr,
	And_chr,
	Semic_chr,
	Pipe_chr,
	Oparenth_chr,
	Cparenth_chr,
	NB_CHR_TYPE
};

enum e_tok_type
{
	Word_tok,
	Pipe_tok,
	Or_tok,
	And_tok,
	Semic_tok,
	Lesser_tok,
	Dlesser_tok,
	Greater_tok,
	Dgreater_tok,
	Amp_tok,
	Oparenth_tok,
	Cparenth_tok
};

enum e_chr_rules
{
	Not_accepted,
	Accepted,
};

typedef struct s_escaped_chrs
{
	char	chr;
	char	escaped_chr;
}	t_escaped_chrs;

typedef struct s_token
{
	char			*data;
	enum e_tok_type	type;
	struct s_token	*next;
}	t_token;

void			build_tok_lst(char *inchars, t_token **tok_lst);

/*
** tok_utils.c
*/

void			clear_tokens(t_token **tok_lst);
void			add_token(t_token *new_tok, t_token **tok_lst);
t_token			*create_token(char *data, enum e_tok_type type);
enum e_chr_type	get_chr_type(char c);
char			*join_chars(char *str, const char *chrs, int nb_chrs);

/*
** tok_word.c
*/

t_token			*tok_word(char *inchars, int *i);

/*
** tok_separators.c
*/

t_token			*tok_semic(char *inchars, int *i);
t_token			*tok_and(char *inchars, int *i);
t_token			*tok_pipe(char *inchars, int *i);
t_token			*tok_parenth(char *inchars, int *i);

/*
** tok_redirections.c
*/

t_token			*tok_lesser(char *inchars, int *i);
t_token			*tok_greater(char *inchars, int *i);

enum e_state
{
	State_general,
	State_insquote,
	State_indquote,
	State_escaped
};

#endif

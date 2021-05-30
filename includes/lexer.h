/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/30 19:45:50 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"
# define NB_QUOTE_CHR 4
# define NB_ESCAPED_CHR 6

enum e_chr_type
{
	Error_chr,
	Alpha_chr,
	Digit_chr,
	Print_chr,
	Space_chr,
	Squote_chr,
	Dquote_chr,
	Dol_chr,
	Less_chr,
	Great_chr,
	And_chr,
	Esc_chr,
	Semic_chr,
	Pipe_chr,
};

typedef enum e_tok_type
{
	Tok_error,
	Word_tok,
	Pipe_tok,
	Or_tok,
	And_tok,
	Semic_tok,
	Lesser_tok,
	Greater_tok,
	Dgreater_tok,
}	t_tok_type;

typedef struct s_escaped_chrs
{
	char	chr;
	char	escaped_chr;
}				t_escaped_chrs;

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
t_token			*create_token(char *data, t_tok_type type);
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
t_token			*tok_lesser(char *inchars, int *i);
t_token			*tok_greater(char *inchars, int *i);

/*
** quote_functions.c
*/

char			*escape_func(const char *inchars, int *i);
char			*squote_func(const char *inchars, int *i);
char			*dquote_func(const char *inchars, int *i);

/*
enum e_chr_type	g_type[128] = {
	[0] = Error_chr,
	[1] = Error_chr,
	[2] = Error_chr,
	[3] = Error_chr,
	[4] = Error_chr,
	[5] = Error_chr,
	[6] = Error_chr,
	[7] = Error_chr,
	[8] = Error_chr,
	['\t' ...'\r'] = Space_chr,
	[14] = Error_chr,
	[15] = Error_chr,
	[16] = Error_chr,
	[17] = Error_chr,
	[18] = Error_chr,
	[19] = Error_chr,
	[20] = Error_chr,
	[21] = Error_chr,
	[22] = Error_chr,
	[23] = Error_chr,
	[24] = Error_chr,
	[25] = Error_chr,
	[26] = Error_chr,
	[27] = Error_chr,
	[28] = Error_chr,
	[29] = Error_chr,
	[30] = Error_chr,
	[31] = Error_chr,
	[' '] = Space_chr,
	['!'] = Error_chr,
	['\"'] = Dquote_chr,
	['#'] = Error_chr,
	['$'] = Dol_chr,
	['%'] = Error_chr,
	['&'] = And_chr,
	['\''] = Back_chr,
	['('] = Error_chr,
	[')'] = Error_chr,
	['*'] = Error_chr,
	['+'] = Error_chr,
	[','] = Error_chr,
	['-'] = Error_chr,
	['.'] = Error_chr,
	['/'] = Error_chr,
	['0' ...'9'] = Digit_chr,
	[':'] = Error_chr,
	[';'] = Semic_chr,
	['<'] = Less_chr,
	['='] = Error_chr,
	['>'] = Great_chr,
	['?'] = Error_chr,
	['@'] = Error_chr,
	['A' ...'Z'] = Alpha_chr,
	['['] = Error_chr,
	['\\'] = Error_chr,
	[']'] = Error_chr,
	['^'] = Error_chr,
	['_'] = Error_chr,
	['`'] = Error_chr,
	['a' ...'z'] = Digit_chr,
	['{'] = Error_chr,
	['|'] = Pipe_chr,
	['}'] = Error_chr,
	['~'] = Error_chr,
	[127] = Error_chr,
};

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

t_token	*tok_alnum(t_token **tok_lst, char *inchars, int *i, t_state *state);
t_token	*tok_squote(t_token **tok_lst, char *inchars, int *i, t_state *state);

int		is_sep(char c);
*/

#endif

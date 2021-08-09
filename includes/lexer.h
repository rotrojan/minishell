/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 20:04:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"
# define SIZE_OF_ONE_CHAR_STR 2
# define SIZE_OF_TWO_CHAR_STR 3

/*
** All the possible char types. Those are useful at two different moments:
** - during the lexing phase, at the beginning of the creation of a token, the
** proper tokenizer will be called accordingly to the char type encountered (if
** the fist character of a token is an alphabetic character, the token will have
** to be a word, if it's a pipe symbol, it will have to be a pipe token or an OR
** token, and so on ... therefore, knowing the type of the token first character
** will allow to call the proper tokenizer in the get_next_token() function.
** - during the word tokenization, some characters can be accepted or no as part
** of a word token, depending on if they are in between quotes or not. See
** tok_word.c for firther informations.
*/

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

/*
** Those are all the possible token types handled by minishell.
*/

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

/*
** Used during the word tokenization. See tok_word.c for further informations.
*/
enum e_chr_rules
{
	Not_accepted,
	Accepted,
};

/*
** A token linked is composed of a data string containing the litteral value of
** the token (the word identifier for example), the type of the token (all types
** are listed above) and a pointer to the next tokeen of the list.
*/

typedef struct s_token
{
	char			*data;
	enum e_tok_type	type;
	struct s_token	*next;
}	t_token;

/*
** lexer.c
*/

bool			build_tok_lst(char *inchars, t_token **tok_lst, t_error *error);

/*
** tok_utils.c
*/

void			clear_tokens(t_token **tok_lst);
void			add_token(t_token *new_tok, t_token **tok_lst);
t_token			*create_token(char *data, enum e_tok_type type);
enum e_chr_type	get_chr_type(char c);

/*
** tok_word.c
*/

t_token			*tok_word(char *inchars, int *i, t_error *error);

/*
** tok_separators.c
*/

t_token			*tok_semic(char *inchars, int *i, t_error *error);
t_token			*tok_and(char *inchars, int *i, t_error *error);
t_token			*tok_pipe(char *inchars, int *i, t_error *error);
t_token			*tok_parenth(char *inchars, int *i, t_error *error);

/*
** tok_redirections.c
*/

t_token			*tok_lesser(char *inchars, int *i, t_error *error);
t_token			*tok_greater(char *inchars, int *i, t_error *error);

#endif

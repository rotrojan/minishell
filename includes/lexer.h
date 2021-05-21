/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/19 13:31:51 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_type
{
	EXPR,
	VAR,
	SQUOTE,
	DQUOTE,
	PIPE,
	OR,
	AMP,
	AND,
	BACKSLASH,
	SEMIC,
	LESSER,
	DLESSER,
	GREATER,
	DGREATER,
	OPARENT,
	CPARENT
}	t_type;

typedef enum e_state
{
	STATE_GENERAL,
	STATE_VAR,
	STATE_INSQUOTE,
	STATE_INDQUOTE,
	STATE_PIPE,
	STATE_AMP,
	STATE_ESCAPED,
	STATE_LESSER,
	STATE_GREATER,
	STATE_INPARENT
}	t_state;

typedef struct s_token
{
	char *data;
	enum e_type type;
	struct s_token *next;
}	t_token;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:57:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/08 19:49:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef char **t_env;

typedef struct s_axe
{
	int					x;
	int					y;
}						t_axe;

typedef struct s_prompt
{
	char				*home;
	char				*user;
	char				*pwd;
	char				*hostname;
}						t_prompt;

typedef struct s_term
{
	struct termios		saved;
	struct termios		current;
}						t_term;

typedef struct s_token
{
	char				value;
	enum e_token_type	type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_cursor
{
	t_axe				pos;
	t_token				*on_token;
}						t_cursor;

typedef struct s_special_key
{
	char				c;
	int					key;
}						t_special_key;

#endif

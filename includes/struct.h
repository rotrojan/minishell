/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:57:34 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/28 22:59:55 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef char	**t_env;

typedef struct s_axe
{
	int	x;
	int	y;
}		t_axe;

typedef struct s_prompt
{
	char	*home;
	char	*user;
	char	*pwd;
	char	*hostname;
}			t_prompt;

typedef struct s_term
{
	struct termios	saved;
	struct termios	current;
}					t_term;

typedef struct s_inchar
{
	char			value;
	struct s_inchar	*next;
	struct s_inchar	*prev;
}					t_inchar;

typedef struct s_history
{
	char				*line;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct s_history_data
{
	char				*input;
	struct s_history	*data;
	struct s_history	*tmp_nav;
}						t_history_data;

typedef struct s_cursor
{
	t_axe		pos;
	t_axe		origin;
	t_inchar	*on_inchar;
}				t_cursor;

typedef struct s_special_key
{
	char	c;
	int		key;
}			t_special_key;

typedef struct s_key
{
	int		key;
	void	(*function)(t_cursor *);
}			t_key;

typedef struct s_builtins
{
	char	*name;
	int		(*function)(int, char **);
}			t_builtins;

typedef struct s_redir_func
{
	enum e_redirection_type	type;
	int						(*function)(t_redirection *);
}							t_redir_func;

#endif

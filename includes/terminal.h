/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 06:57:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/29 23:10:22 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# define _XOPEN_SOURCE 700
# ifdef __linux__
#  define OS 1
# elif __APPLE__
#  define OS 0
# endif
# define SIGWINCH 28
# define CTRL_C 2
# define CTRL_D 4
# define DELETE 8
# define TAB 9
# define CTRL_L 12
# define ESC 27
# define BACKSPACE 127

typedef struct s_term
{
	struct termios	saved;
	struct termios	current;
}	t_term;

typedef struct s_axe
{
	int	x;
	int	y;
}	t_axe;

typedef struct s_prompt
{
	char	*home;
	char	*user;
	char	*pwd;
	char	*hostname;
}	t_prompt;

typedef struct s_inchar
{
	char			value;
	struct s_inchar	*next;
	struct s_inchar	*prev;
}	t_inchar;

typedef struct s_cursor
{
	t_axe		pos;
	t_axe		origin;
	t_inchar	*on_inchar;
}	t_cursor;

typedef struct s_special_key
{
	char	c;
	int		key;
}	t_special_key;

typedef struct s_key
{
	int		key;
	void	(*function)(t_cursor *);
}	t_key;

int		ft_getch(void);
t_term	*getterm(void);
t_term	*set_termios(void);
t_axe	get_cursor_pos(void);
void	end_key(t_cursor *cursor);
void	home_key(t_cursor *cursor);
void	delete_key(t_cursor *cursor);
void	ctrl_d_key(t_cursor *cursor);
void	ctrl_l_key(t_cursor *cursor);
void	backspace_key(t_cursor *cursor);
void	left_arrow_key(t_cursor *cursor);
void	right_arrow_key(t_cursor *cursor);
int		cursor_move_left(t_cursor *cursor);
int		cursor_move_right(t_cursor *cursor);

#endif

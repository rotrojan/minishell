/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/04 08:07:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	control_key(t_cursor *cursor, int c)
{
	int			i;
	t_key const	keys[] = {
		{.key = BACKSPACE, .function = &backspace_key},
		{.key = DELETE, .function = &delete_key},
		{.key = KEY_LEFT, .function = &left_arrow_key},
		{.key = KEY_END, .function = &end_key},
		{.key = KEY_RIGHT, .function = &right_arrow_key},
		{.key = KEY_HOME, .function = &home_key},
		{.key = CTRL_L, .function = &ctrl_l_key},
		{.key = KEY_UP, .function = &history_get_up},
		{.key = KEY_DOWN, .function = &history_get_down},
		{.key = -1}
	};

	i = 0;
	while (keys[i].key > 0)
	{
		if (c == keys[i].key)
			keys[i].function(cursor);
		i++;
	}
}

static char	*get_line(t_cursor *cursor, int c)
{
	char		*line;

	if (c == CTRL_D)
	{
		line = gc_malloc(sizeof(char) * 1);
		line[0] = EOF;
	}
	else
	{
		line = inchars_to_line(cursor);
		if (line != NULL && ft_striter(line, &ft_isspace) == 1)
			gc_free((void **)&line);
		free_inchars(cursor);
	}
	return (line);
}

static int	catch_signals(void)
{
	int	sig;

	handle_signals();
	sig = *get_signal_on();
	if (sig == SIGINT)
		ft_putstr_fd("^C\n", STDERR_FILENO);
	return (sig);
}

/* Read and return input line for shell. */
static char	*input(void)
{
	int				c;
	int				sig;
	t_cursor		cursor;

	cursor.on_inchar = create_inchar(EOL);
	cursor.pos = get_cursor_pos();
	cursor.origin = cursor.pos;
	while (true)
	{
		sig = catch_signals();
		if (sig == SIGINT)
			return (NULL);
		else if (sig == SIGWINCH)
			ctrl_l_key(&cursor);
		c = ft_getch();
		if (c != ERR)
		{
			if (c == '\n' || (c == CTRL_D && inchars_len(&cursor) == 1))
				return (get_line(&cursor, c));
			else if (ft_iscntrl(c) == 1)
				control_key(&cursor, c);
			else
				insert_inchar(&cursor, c);
		}
	}
}

char	*ft_readline(void)
{
	char	*line;
	t_term	*term;

	term = set_termios();
	line = input();
	tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
	return (line);
}

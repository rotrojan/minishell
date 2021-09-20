/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:50:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/15 21:50:01 by lucocozz         ###   ########.fr       */
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
	if (c == CTRL_D)
		exit_shell(EXIT_SUCCESS, "\n");
	while (keys[i].key > 0)
	{
		if (c == keys[i].key)
			keys[i].function(cursor);
		i++;
	}
}

static char	*get_line(t_cursor *cursor)
{
	char	*line;

	line = inchars_to_line(inchars_head(cursor));
	free_inchars(inchars_head(cursor));
	if (ft_striter(line, &ft_isspace) == 1)
	{
		gc_free((void **)&line);
		return (ft_strdup(""));
	}
	return (line);
}

static int	catch_signals(void)
{
	int	*sig;
	int	tmp;

	handle_signals();
	sig = get_signal_on();
	tmp = *sig;
	*sig = 0;
	if (tmp == SIGINT)
		ft_putstr("^C");
	return (tmp);
}

/*	"cr" = put cursor at the beginning of the line
	"cd" = clear screen from the cursor to the end	*/
static void	update_screen(t_cursor *cursor)
{
	char		*goto_cap;

	cursor->pos = get_cursor_pos();
	while (cursor->on_inchar->prev != NULL)
	{
		cursor_move_left(cursor);
		cursor->on_inchar = cursor->on_inchar->prev;
	}
	goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
	tputs(goto_cap, 1, ft_putchar_err);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	print_inchars(cursor->on_inchar);
	while (cursor->on_inchar->next != NULL)
	{
		cursor_move_right(cursor);
		cursor->on_inchar = cursor->on_inchar->next;
	}
}

/* Read and return input line for shell. */
char	*input(void)
{
	int				c;
	int				sig;
	t_cursor		cursor;

	cursor.on_inchar = create_inchar(EOL);
	cursor.pos = get_cursor_pos();
	while (1)
	{
		sig = catch_signals();
		if (sig == SIGINT)
			return (ft_strdup(""));
		else if (sig == SIGWINCH)
			update_screen(&cursor);
		c = ft_getch();
		if (c != ERR)
		{
			if (c == '\n')
				return (get_line(&cursor));
			else if (!ft_iscntrl(c))
				insert_inchar(&cursor, c);
			else
				control_key(&cursor, c);
		}
	}
}

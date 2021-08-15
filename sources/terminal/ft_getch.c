/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:59:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 15:07:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_special_key(int c)
{
	int					i;
	t_special_key const	special_key[] = {{'A', KEY_UP}, {'B', KEY_DOWN},
	{'C', KEY_RIGHT}, {'D', KEY_LEFT}, {'H', KEY_HOME}, {'F', KEY_END}};

	i = 0;
	if (c == '3')
	{
		if (read(STDIN_FILENO, &c, 1) < 1)
			return (ERR);
		return (DELETE);
	}
	while (i < NB_SPECIAL_KEY)
	{
		if (c == special_key[i].c)
			break ;
		i++;
	}
	if (i == NB_SPECIAL_KEY)
		return (ERR);
	return (special_key[i].key);
}

static int	special_key(void)
{
	int		c;
	int		key;
	t_term	*term;

	c = 0;
	key = 0;
	term = getterm();
	set_timeout(term, 0);
	if (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (read(STDIN_FILENO, &c, 1) > 0)
			key = get_special_key(c);
		else
			key = ERR;
	}
	else
		key = ESC;
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	return (key);
}

/* Read one char in input, else return ERR if can't read.
Can read special char like arrow key.
You must have set the terminal to non-canonical
and without echo before. */
int	ft_getch(void)
{
	int	c;

	c = 0;
	if (read(STDIN_FILENO, &c, 1) <= 0)
		return (ERR);
	if (c == CTRL_D)
		exit_shell(EXIT_SUCCESS, "\nexit\n");
	if (c == ESC)
		return (special_key());
	return (c);
}

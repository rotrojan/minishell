/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:59:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 23:20:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_special_key(int c)
{
	int					i;
	t_special_key const	special_key[] = {
		{.c = 'A', .key = KEY_UP}, {.c = 'B', .key = KEY_DOWN},
		{.c = 'C', .key = KEY_RIGHT}, {.c = 'D', .key = KEY_LEFT},
		{.c = 'H', .key = KEY_HOME}, {.c = 'F', .key = KEY_END},
		{.c = -1, .key = -1}
	};

	i = 0;
	if (c == '3')
	{
		if (read(STDIN_FILENO, &c, 1) < 1)
			return (ERR);
		return (DELETE);
	}
	while (special_key[i].c != -1)
	{
		if (c == special_key[i].c)
			break ;
		i++;
	}
	if (special_key[i].c == -1)
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
	if (c == ESC)
		return (special_key());
	return (c);
}

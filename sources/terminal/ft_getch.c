/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:59:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/10 02:13:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_timeout(t_term *term, int timeout)
{
	struct termios	tmp;

	tmp = term->current;
	tmp.c_cc[VMIN] = 0;
	tmp.c_cc[VTIME] = timeout;
	tcsetattr(STDIN_FILENO, TCSANOW, &tmp);
}

static int	get_special_key(int c)
{
	int							i;
	static const t_special_key	special_key[] = {{'A', KEY_UP}, {'B', KEY_DOWN},
	{'C', KEY_RIGHT}, {'D', KEY_LEFT}, {'H', KEY_HOME}, {'F', KEY_END}};

	i = 0;
	while (i < NB_SPECIAL_KEY)
	{
		if (c == special_key[i].c)
			break ;
		i++;
	}
	return (special_key[i].key);
}

static int	special_key(void)
{
	int							c;
	int							key;
	t_term						*term;

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
		key = KEY_ESC;
	tcsetattr(STDIN_FILENO, TCSANOW, &term->current);
	return (key);
}

int	ft_getch(void)
{
	int	c;

	c = 0;
	if (read(STDIN_FILENO, &c, 1) <= 0)
		return (ERR);
	if (c == KEY_ESC)
		return (special_key());
	return (c);
}

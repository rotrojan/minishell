/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:43:48 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/13 04:51:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	left_arrow_key(t_cursor *cursor)
{
	char	*goto_cap;

	if (cursor->on_token->prev != NULL)
	{
		cursor->on_token = cursor->on_token->prev;
		cursor->pos.y--;
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar);
	}
}

void	right_arrow_key(t_cursor *cursor)
{
	char	*goto_cap;

	if (cursor->on_token->next != NULL)
	{
		cursor->on_token = cursor->on_token->next;
		cursor->pos.y++;
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar);
	}
}

void	backspace_key(t_cursor *cursor)
{
	char	*goto_cap;
	t_token	*tmp;

	if (cursor->on_token->prev != NULL)
	{
		tmp = cursor->on_token->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = cursor->on_token;
		cursor->on_token->prev = tmp->prev;
		gc_free(tmp);
		cursor->pos.y--;
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		tputs(goto_cap, 1, ft_putchar);
		ft_putxchar(' ', tokens_len(cursor->on_token));
		tputs(goto_cap, 1, ft_putchar);
		print_tokens(cursor->on_token);
		tputs(goto_cap, 1, ft_putchar);
	}
}

void	delete_key(t_cursor *cursor)
{
	char	*goto_cap;
	t_token	*tmp;

	if (cursor->on_token->value != EOL)
	{
		tmp = cursor->on_token->next;
		if (cursor->on_token->prev != NULL)
			cursor->on_token->prev->next = tmp;
		tmp->prev = cursor->on_token->prev;
		gc_free(cursor->on_token);
		cursor->on_token = tmp;
		goto_cap = tgoto(tgetstr("cm", NULL), cursor->pos.y, cursor->pos.x);
		ft_putxchar(' ', tokens_len(cursor->on_token));
		tputs(goto_cap, 1, ft_putchar);
		print_tokens(cursor->on_token);
		tputs(goto_cap, 1, ft_putchar);
	}
}

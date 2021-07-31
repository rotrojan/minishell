/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:59:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/31 19:16:13 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eat_token(t_token **tok_lst)
{
	t_token	*tmp;

	tmp = *tok_lst;
	if (*tok_lst == NULL)
		return ;
	*tok_lst = (*tok_lst)->next;
	gc_free(tmp->data);
	tmp->data = NULL;
	gc_free(tmp);
	tmp = NULL;
}

t_bool	build_ast(t_token **tok_lst, t_node **ast)
{
	t_bool	ret;

	while (*tok_lst != NULL)
	{
		if (is_logical_operator((*tok_lst)->type) == True)
			ret = parse_logical_operator(tok_lst, ast);
		else if (is_pipe((*tok_lst)->type) == True)
			ret = parse_pipe(tok_lst, ast);
		else if (is_leaf((*tok_lst)->type) == True)
			ret = parse_simple_cmd(tok_lst, ast);
		else if ((*tok_lst)->type == Amp_tok)
			return (False);
		if (ret == False)
			return (False);
	}
	return (True);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:59:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/22 00:08:52 by rotrojan         ###   ########.fr       */
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

void	print_array(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("\n%s", av[i++]);
		fflush(stdout);
	}
}

void	build_ast(t_token **tok_lst, t_node **ast)
{
	while (*tok_lst != NULL)
	{
		*ast = parse_simple_cmd(tok_lst);
		if (*ast == NULL)
			return (display_error(UNEXPECTED_TOKEN, ast, tok_lst));
		if (*ast && (*ast)->type == Simple_cmd)
			print_array((*ast)->content.simple_cmd.argv);
	}
}

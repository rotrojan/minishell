/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:59:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/18 20:26:51 by rotrojan         ###   ########.fr       */
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

void	add_node(t_node	*node, t_node **ast, t_token **tok_lst)
{
	if (*ast == NULL)
	{
		if (node->type != Simple_cmd)
			return (display_error(UNEXPECTED_TOKEN, tok_lst));
		*ast = node;
	}
}

void	print_array(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		printf("\n%s", av[i++]);
}

t_node	*create_node(t_node_type node_type)
{
	t_node	*new_node;

	new_node = NULL;
	new_node = gc_malloc(sizeof(*new_node));
	ft_bzero(new_node, sizeof(*new_node));
	new_node->type = node_type;
	return (new_node);
}

void	build_ast(t_token **tok_lst, t_node **ast)
{
	while (*tok_lst != NULL)
	{
		if (is_leaf((*tok_lst)->type) == True)
			add_node(parse_simple_cmd(tok_lst), ast, tok_lst);
		else
			add_node(create_node((t_node_type)(*tok_lst)->type), ast, tok_lst);
		print_array((*ast)->content.simple_cmd.argv);
	}
}

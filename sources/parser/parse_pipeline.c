/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:30:31 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 00:30:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*allocate_and_init_pipe_node(t_token **tok_lst)
{
	t_node	*pipe_node;

	pipe_node = NULL;
	pipe_node = gc_malloc(sizeof(*pipe_node));
	ft_bzero(pipe_node, sizeof(*pipe_node));
	pipe_node->type = Pipe_node;
	eat_token(tok_lst);
	return (pipe_node);
}

bool	parse_pipeline(t_token **tok_lst, t_node **ast)
{
	t_node	*pipe_node;
	t_node	*simple_cmd;
	t_node	*pipeline;
	bool	ret;

	ret = TRUE;
	if ((*tok_lst)->type == Oparenth_tok)
		return (parse_parenthesis(tok_lst, ast));
	if (parse_simple_cmd(tok_lst, &simple_cmd) == FALSE)
		return (FALSE);
	pipeline = simple_cmd;
	while (*tok_lst != NULL && (*tok_lst)->type == Pipe_tok)
	{
		pipe_node = allocate_and_init_pipe_node(tok_lst);
		pipe_node->content.child.left = pipeline;
		pipeline = pipe_node;
		if (*tok_lst != NULL && is_parenthesis((*tok_lst)->type) == TRUE)
			ret = parse_parenthesis(tok_lst, &(pipeline->content.child.right));
		else
			ret = parse_simple_cmd(tok_lst, &(pipeline->content.child.right));
		if (ret == FALSE)
			break ;
	}
	*ast = pipeline;
	return (ret);
}

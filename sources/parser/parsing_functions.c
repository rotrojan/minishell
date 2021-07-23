/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:07:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/22 22:50:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define REDIR_TOK_TYPE_OFFSET 5

static void	add_redirection(t_token **current, t_node *simple_cmd)
{
	t_redirection	*new_redirection;

	new_redirection = NULL;
	new_redirection = gc_malloc(sizeof(*new_redirection));
	ft_bzero(new_redirection, sizeof(*new_redirection));
	new_redirection->type
		= (enum e_redirection_type)(*current)->type - REDIR_TOK_TYPE_OFFSET;
	new_redirection->stream = ft_strdup((*current)->next->data);
	new_redirection->next = simple_cmd->content.simple_cmd.redirection;
	simple_cmd->content.simple_cmd.redirection = new_redirection;
}

static char	**from_lst_to_array(t_token **tok_lst, int argc)
{
	char	**argv;
	int		i;

	argv = NULL;
	argv = gc_malloc(sizeof(char *) * (argc + 1));
	i = 0;
	while (*tok_lst != NULL && is_leaf((*tok_lst)->type) == TRUE)
	{
		if ((*tok_lst)->type == Word_tok)
			argv[i++] = ft_strdup((*tok_lst)->data);
		else if (is_redirection((*tok_lst)->type) == True)
			eat_token(tok_lst);
		eat_token(tok_lst);
	}
	argv[i] = NULL;
	return (argv);
}

t_bool	parse_simple_cmd(t_token **tok_lst, t_node **ast)
{
	t_token	*current;
	t_node	*simple_cmd;

	if (is_separator((*tok_lst)->type) == True
		|| is_pipe((*tok_lst)->type) == True)
		return (False);
	simple_cmd = NULL;
	simple_cmd = gc_malloc(sizeof(*simple_cmd));
	ft_bzero(simple_cmd, sizeof(*simple_cmd));
	simple_cmd->type = Simple_cmd;
	current = *tok_lst;
	while (current != NULL && is_leaf(current->type) == TRUE)
	{
		if (current->type == Word_tok)
			simple_cmd->content.simple_cmd.argc += 1;
		else if (is_redirection(current->type) == True)
			add_redirection(&current, simple_cmd);
		current = current->next;
	}
	simple_cmd->content.simple_cmd.argv
		= from_lst_to_array(tok_lst, simple_cmd->content.simple_cmd.argc);
	*ast = simple_cmd;
	return (True);
}

t_bool	parse_pipe(t_token **tok_lst, t_node **ast)
{
	t_node	*pipe_node;

	if (*ast == NULL)
		return (False);
	pipe_node = NULL;
	pipe_node = gc_malloc(sizeof(*pipe_node));
	ft_bzero(pipe_node, sizeof(*pipe_node));
	pipe_node->type = Pipe_node;
	pipe_node->content.child.left = *ast;
	*ast = pipe_node;
	eat_token(tok_lst);
	return (parse_simple_cmd(tok_lst, &((*ast)->content.child.right)));
}

t_bool	parse_separator(t_token **tok_lst, t_node **ast)
{
	t_node	*separator_node;

	if (*ast == NULL)
		return (False);
	separator_node = NULL;
	separator_node = gc_malloc(sizeof(*separator_node));
	ft_bzero(separator_node, sizeof(*separator_node));
	separator_node->type = (enum e_node_type)((*tok_lst)->type);
	separator_node->content.child.left = *ast;
	*ast = separator_node;
	eat_token(tok_lst);
	return (build_ast(tok_lst, &((*ast)->content.child.right)));
}

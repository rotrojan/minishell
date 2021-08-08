/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:07:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/08 18:09:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define REDIR_TOK_TYPE_OFFSET 5

static bool	add_redirection(t_token **tok_lst, t_node *simple_cmd)
{
	t_redirection	*new_redirection;

	if ((*tok_lst)->next == NULL)
	{
		eat_token(tok_lst);
		return (FALSE);
	}
	new_redirection = NULL;
	new_redirection = gc_malloc(sizeof(*new_redirection));
	ft_bzero(new_redirection, sizeof(*new_redirection));
	new_redirection->type
		= (enum e_redirection_type)(*tok_lst)->type - REDIR_TOK_TYPE_OFFSET;
	eat_token(tok_lst);
	if ((*tok_lst)->type != Word_tok)
		return (FALSE);
	new_redirection->stream = ft_strdup((*tok_lst)->data);
	new_redirection->next = simple_cmd->content.simple_cmd.redirection;
	simple_cmd->content.simple_cmd.redirection = new_redirection;
	return (TRUE);
}

static bool	from_lst_to_array(t_token **tok_lst, t_node *simple_cmd)
{
	int		i;

	i = 0;
	simple_cmd->content.simple_cmd.argv = gc_malloc(sizeof(char *)
			* (simple_cmd->content.simple_cmd.argc + 1));
	ft_bzero(simple_cmd->content.simple_cmd.argv,
		sizeof(simple_cmd->content.simple_cmd.argv));
	while (*tok_lst != NULL && is_leaf((*tok_lst)->type) == TRUE)
	{
		if ((*tok_lst)->type == Word_tok)
			simple_cmd->content.simple_cmd.argv[i++]
				= ft_strdup((*tok_lst)->data);
		else if (is_redirection((*tok_lst)->type) == TRUE)
		{
			if (add_redirection(tok_lst, simple_cmd) == FALSE)
				return (FALSE);
		}
		eat_token(tok_lst);
	}
	simple_cmd->content.simple_cmd.argv[i] = NULL;
	return (TRUE);
}

static unsigned int	get_argc(t_token *tok_lst)
{
	unsigned int	argc;
	t_token			*current;

	argc = 0;
	current = tok_lst;
	while (current != NULL && is_leaf(current->type) == TRUE)
	{
		if (current->type == Word_tok)
			++argc;
		else if (is_redirection(current->type) == TRUE)
			if (current->next != NULL)
				current = current->next;
		current = current->next;
	}
	return (argc);
}

bool	parse_simple_cmd(t_token **tok_lst, t_node **ast)
{
	t_node	*simple_cmd;

	if ((*tok_lst)->type == Oparenth_tok)
		return (parse_parenthesis(tok_lst, ast));
	if (is_leaf((*tok_lst)->type) == FALSE)
		return (FALSE);
	simple_cmd = NULL;
	simple_cmd = gc_malloc(sizeof(*simple_cmd));
	ft_bzero(simple_cmd, sizeof(*simple_cmd));
	simple_cmd->type = Simple_cmd;
	simple_cmd->content.simple_cmd.argc = get_argc(*tok_lst);
	if (from_lst_to_array(tok_lst, simple_cmd) == FALSE)
	{
		gc_free(simple_cmd);
		return (FALSE);
	}
	*ast = simple_cmd;
	return (TRUE);
}

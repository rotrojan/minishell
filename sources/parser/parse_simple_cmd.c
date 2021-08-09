/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:07:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/09 21:56:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define REDIR_TOK_TYPE_OFFSET 5

/*
** Malloc and add the redirection to the redirection linked list of the simple
** command.
*/

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

/*
** The from_lst_to_array() function will malloc and fill the argv array of
** strings containing the arguments of the command. If a redirection is
** encountered, it will be handled by the add_redirection() function. The tokens
** of the tok_lst linked list are eaten progressivly along the process.
*/

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

/*
** The get_argc() function returns the number of arguments of the simple command
** by iterating on the tok_lst token linked list while the tokens are not
** separators. Redirection tokens are not taken in the count.
*/

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

/*
** Parsing a simple command is done the following way:
** - if the token is not a leaf, it is a syntax error: FALSE is returned;
** - the simple_command node is maloced;
** - the number of arguments of the command is obtained with get_argc();
** - from_lst_to_array() fills the argv array and the redirection linked list of
** the simple command leaf.
*/

bool	parse_simple_cmd(t_token **tok_lst, t_node **ast)
{
	t_node	*simple_cmd;

	if (is_leaf((*tok_lst)->type) == FALSE)
		return (FALSE);
	simple_cmd = NULL;
	simple_cmd = gc_malloc(sizeof(*simple_cmd));
	ft_bzero(simple_cmd, sizeof(*simple_cmd));
	simple_cmd->type = Simple_cmd;
	simple_cmd->content.simple_cmd.argc = get_argc(*tok_lst);
	if (from_lst_to_array(tok_lst, simple_cmd) == FALSE
		|| (*tok_lst != NULL && (*tok_lst)->type == Oparenth_tok))
	{
		gc_free(simple_cmd);
		return (FALSE);
	}
	*ast = simple_cmd;
	return (TRUE);
}

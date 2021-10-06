/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:07:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/06 18:04:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** The get_argc() function returns the number of arguments of the simple command
** by iterating on the tok_lst token linked list while the tokens are not
** separators. Redirection tokens are not taken in the count.
** On success, true is returned.
*/


static unsigned int	get_nb_args(t_token *tok_lst)
{
	unsigned int	nb_args;
	t_token			*current;

	nb_args = 0;
	current = tok_lst;
	while (current != NULL && is_leaf(current->type) == true)
	{
		++nb_args;
		current = current->next;
	}
	return (nb_args);
}

/*
** The from_lst_to_array() function will malloc and fill the argv array of
** strings containing the arguments of the command. If a redirection is
** encountered, it will be handled by the add_redirection() function. The tokens
** of the tok_lst linked list are eaten progressivly along the process.
*/

static bool	from_lst_to_array(t_token **tok_lst, t_node *simple_cmd)
{
	int	i;

	i = 0;
	simple_cmd->content.simple_cmd.argv = gc_malloc(sizeof(char *)
			* (get_nb_args(*tok_lst) + 1));
	ft_bzero(simple_cmd->content.simple_cmd.argv,
		sizeof(simple_cmd->content.simple_cmd.argv));
	while (*tok_lst != NULL && is_leaf((*tok_lst)->type) == true)
	{
		simple_cmd->content.simple_cmd.argv[i++] = ft_strdup((*tok_lst)->data);
		eat_token(tok_lst);
	}
	simple_cmd->content.simple_cmd.argv[i] = NULL;
	return (true);
}


/*
** Parsing a simple command is done the following way:
** - if the token is not a leaf, it is a syntax error: false is returned;
** - the simple_command node is maloced;
** - the number of arguments of the command is obtained with get_argc();
** - from_lst_to_array() fills the argv array and the redirection linked list of
** the simple command leaf.
*/

bool	parse_simple_cmd(t_token **tok_lst, t_node **ast)
{
	t_node	*simple_cmd;

	if ((*tok_lst)->type == Oparenth_tok)
		return (parse_parenthesis(tok_lst, ast));
	if (is_leaf((*tok_lst)->type) == false)
		return (false);
	simple_cmd = NULL;
	simple_cmd = gc_malloc(sizeof(*simple_cmd));
	ft_bzero(simple_cmd, sizeof(*simple_cmd));
	simple_cmd->type = Simple_cmd;
	if (from_lst_to_array(tok_lst, simple_cmd) == false
		|| (*tok_lst != NULL && (*tok_lst)->type == Oparenth_tok))
		return (false);
	if ((*tok_lst) != NULL && (*tok_lst)->type == Oparenth_tok)
		return (print_error_and_return(*tok_lst));
	*ast = simple_cmd;
	return (true);
}

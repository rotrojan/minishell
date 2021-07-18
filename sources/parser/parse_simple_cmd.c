/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:07:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/18 20:12:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_redirection(enum e_tok_type type)
{
	if (type == Lesser_tok)
		return (True);
	if (type == Dlesser_tok)
		return (True);
	if (type == Greater_tok)
		return (True);
	if (type == Dgreater_tok)
		return (True);
	return (False);
}

t_bool	is_leaf(enum e_tok_type type)
{
	if (is_redirection(type) == True)
		return (True);
	if (type == Word_tok)
		return (True);
	return (False);
}

void	add_redirection(t_token **tok_lst, t_node *simple_cmd)
{
	t_redirection	*new_redirection;

	new_redirection = NULL;
	new_redirection = gc_malloc(sizeof(*new_redirection));
	ft_bzero(new_redirection, sizeof(*new_redirection));
	if ((*tok_lst)->type == Dgreater_tok)
		new_redirection->type = Append_output_redir;
	if ((*tok_lst)->type == Greater_tok)
		new_redirection->type = Output_redir;
	if ((*tok_lst)->type == Lesser_tok)
		new_redirection->type = Input_redir;
	if ((*tok_lst)->type == Dlesser_tok)
		new_redirection->type = Heredoc_redir;
	eat_token(tok_lst);
	new_redirection->stream = ft_strdup((*tok_lst)->data);
	new_redirection->next = simple_cmd->content.simple_cmd.redirection;
	simple_cmd->content.simple_cmd.redirection = new_redirection->next;
	eat_token(tok_lst);
}

char	**from_lst_to_array(t_token **tok_lst, int argc)
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
		eat_token(tok_lst);
	}
	argv[i] = NULL;
	return (argv);
}

t_node	*parse_simple_cmd(t_token **tok_lst)
{
	t_token	*current;
	t_node	*simple_cmd;

	simple_cmd = NULL;
	simple_cmd = gc_malloc(sizeof(*simple_cmd));
	ft_bzero(simple_cmd, sizeof(*simple_cmd));
	simple_cmd->type = Simple_cmd;
	current = *tok_lst;
	while (current != NULL && is_leaf(current->type) == TRUE)
	{
		if (current->type == Word_tok)
			simple_cmd->content.simple_cmd.argc += 1;
		else
			add_redirection(tok_lst, simple_cmd);
		current = current->next;
	}
	simple_cmd->content.simple_cmd.argv
		= from_lst_to_array(tok_lst, simple_cmd->content.simple_cmd.argc);
	return (simple_cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:00:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/22 01:04:11 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_node_type
{
	Simple_cmd,
	Pipe_node,
	Or_node,
	And_node,
	Semic_node
}	t_node_type;

typedef enum e_redirection_type
{
	Output_redir,
	Append_output_redir,
	Input_redir,
	Heredoc_redir
}	t_redirection_type;

typedef struct s_redirection
{
	char					*stream;
	t_redirection_type		type;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_simple_cmd
{
	int				argc;
	char			**argv;
	t_redirection	*redirection;
}	t_simple_cmd;

typedef struct s_child
{
	struct s_node	*left;
	struct s_node	*right;
}	t_child;

typedef union u_node_content
{
	struct s_simple_cmd	simple_cmd;
	struct s_child		child;
}	t_node_content;

typedef struct s_node
{
	t_node_type		type;
	t_node_content	content;
}	t_node;

/*
** build_ast.c
*/

void	build_ast(t_token **tok_lst, t_node **ast);
void	eat_token(t_token **tok_lst);

/*
** free_ast.c
*/

void	clear_ast(t_node **ast);

/*
** parse_simple_cmd.c
*/

void	add_redirection(t_token **tok_lst, t_node *simple_cmd);
char	**from_lst_to_array(t_token **tok_lst, int argc);
t_node	*parse_simple_cmd(t_token **tok_lst);

t_bool	is_leaf(enum e_tok_type type);
t_bool	is_redirection(enum e_tok_type type);
t_bool	is_separator(enum e_tok_type type);
t_bool	is_pipe(enum e_tok_type type);

#endif

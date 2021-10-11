/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:00:41 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/10 16:12:13 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** All the possible types of nodes that can be found in the AST. Here, leaves
** are also considered as nodes.
*/

enum e_node_type
{
	Simple_cmd,
	Pipe_node,
	Or_node,
	And_node,
	Semic_node
};

/*
** All the possible types of redirections that can be found in a simple command.
*/

enum e_redirection_type
{
	Input_redir,
	Heredoc_redir,
	Output_redir,
	Append_output_redir,
	No_redir
};

/*
** A simple command (aka, the leaves of the tree) is composed of an number of
** arguments argc, an array of strings of arguments argv and a linked list of
** redirections.
*/

typedef struct s_simple_cmd
{
	char	**argv;
	int		fd_in;
	int		fd_out;
	bool	input_stream_has_quotes;
}	t_simple_cmd;

/*
** A node in the AST always have to children: right and left.
*/

typedef struct s_child
{
	struct s_node	*left;
	struct s_node	*right;
}	t_child;

/*
** If the member of the AST is a leaf, it contains a simple command. Otherwise,
** if it is a node, it has two children.
*/

typedef union u_node_content
{
	struct s_simple_cmd	simple_cmd;
	struct s_child		child;
}	t_node_content;

/*
** A member of the AST contains a node_type and a content wich can be a simple
** command or children.
*/

typedef struct s_node
{
	enum e_node_type	type;
	t_node_content		content;
}	t_node;

/*
** build_ast.c
*/

bool	print_error_and_return(t_token *token);
bool	build_ast(t_token **tok_lst, t_node **ast);
void	eat_token(t_token **tok_lst);

/*
** free_ast.c
*/

void	clear_ast(t_node **ast);

/*
** parse_simple_cmd.c
*/

bool	parse_simple_cmd(t_token **tok_lst, t_node **ast);

/*
** parse_logical_operator.c
*/

bool	parse_logical_operator(t_token **tok_lst, t_node **ast);

/*
** parse_parenthesis.c
*/

bool	parse_parenthesis(t_token **tok_lst, t_node **ast);

/*
** parse_pipeline.c
*/

bool	parse_pipeline(t_token **tok_lst, t_node **ast);

/*
** token_identifiers.c
*/

bool	is_leaf(enum e_tok_type type);
bool	is_redirection(enum e_tok_type type);
bool	is_parenthesis(enum e_tok_type type);
bool	is_logical_operator(enum e_tok_type type);

#endif

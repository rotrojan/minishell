/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/22 05:04:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void display_parsing_error(t_token *tok_lst)
{
	if (tok_lst == NULL)
		ft_dprintf(STDERR_FILENO,
			"\nminishell: syntax error: unexpected end of file");
	else if (tok_lst->type == Amp_tok)
		ft_dprintf(STDERR_FILENO,
			"\nminishell: the `&' operator is not handled by minishell");
	else if (tok_lst == NULL)
		ft_dprintf(STDERR_FILENO,
			"\nminishell: syntax error near unexpected token `newline'");
	else
		ft_dprintf(STDERR_FILENO,
			"\nminishell: syntax error near unexpected token `%s'",
			tok_lst->data);
}

static t_node	*lexer_parser(char *line)
{
	t_token	*tok_lst;
	t_node	*ast;

	ast = NULL;
	tok_lst = NULL;
	ast = NULL;
	if (build_tok_lst(line, &tok_lst) == true)
	{
		if (build_ast(&tok_lst, &ast) == false)
		{
			display_parsing_error(tok_lst);
			clear_ast(&ast);
		}
	}
	clear_tokens(&tok_lst);
	return (ast);
}

/* Core of program */
void	shell(bool inline_mode)
{
	char	*line;
	t_node	*ast;
	t_term	*term;

	ast = NULL;
	while (1)
	{
		if (inline_mode == true)
			get_next_line(STDIN_FILENO, &line);
		else
		{
			term = set_termios();
			prompt();
			line = input();
			tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
		}
		if (line[0] != '\0')
		{
			put_in_history(line);
			ast = lexer_parser(line);
			if (ast != NULL)
			{
				exec_ast(ast, inline_mode);
				clear_ast(&ast);
			}
			else
				ft_dprintf(STDERR_FILENO, "\n\r");
		}
		else
		{
			ft_dprintf(STDERR_FILENO, "\n\r");
			gc_free((void **)&line);
		}
		if (inline_mode == true)
			exit_shell(EXIT_SUCCESS, NULL);
	}
}

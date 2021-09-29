/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/29 20:59:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*lexer_parser(char *line)
{
	t_token	*tok_lst;
	t_node	*ast;

	ast = NULL;
	tok_lst = NULL;
	ast = NULL;
	if (build_tok_lst(line, &tok_lst) == true)
	{
		if (build_ast(&tok_lst, &ast) == false || tok_lst != NULL)
		{
			if (tok_lst != NULL)
				ft_dprintf(STDERR_FILENO,
					"\nminishell: syntax error near unexpected token `%s'",
					tok_lst->data);
			set_exit_value(EXIT_SYNTAX_ERROR);
			clear_ast(&ast);
		}
	}
	else
		set_exit_value(EXIT_SYNTAX_ERROR);
	clear_tokens(&tok_lst);
	return (ast);
}

static void	execution(char *line, bool inline_mode)
{
	t_node	*ast;

	ast = NULL;
	if (line != NULL)
	{
		put_in_history(line);
		ast = lexer_parser(line);
		if (ast != NULL)
		{
			exec_ast(ast, inline_mode);
			clear_ast(&ast);
			set_is_piped(false);
		}
		else
			ft_dprintf(STDERR_FILENO, "\n\r");
	}
	else
	{
		if (*get_signal_on() != SIGINT)
			ft_dprintf(STDERR_FILENO, "\n\r");
		gc_free((void **)&line);
	}
}

/* Core of program */
void	shell(bool inline_mode)
{
	char	*line;
	t_term	*term;

	while (true)
	{
		set_signal_on(0);
		if (inline_mode == true)
		{
			if (get_next_line(STDIN_FILENO, &line) == -1
				|| ft_striter(line, &ft_isprint) == 0)
				return (gc_free((void **)&line));
		}
		else
		{
			term = set_termios();
			prompt();
			line = input();
			tcsetattr(STDIN_FILENO, TCSANOW, &term->saved);
		}
		execution(line, inline_mode);
		if (inline_mode == true)
			exit_shell(*get_exit_value(), NULL);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/23 22:29:19 by rotrojan         ###   ########.fr       */
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
		if (build_ast(&tok_lst, &ast) == false)
		{
			set_exit_value(EXIT_SYNTAX_ERROR);
			clear_ast(&ast);
		}
	}
	else
		set_exit_value(EXIT_SYNTAX_ERROR);
	clear_tokens(&tok_lst);
	return (ast);
}

static void	execution(char **line, bool inline_mode)
{
	t_node	*ast;

	ast = NULL;
	if ((*line)[0] != '\0')
	{
		put_in_history(*line);
		ast = lexer_parser(*line);
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
		gc_free((void **)line);
	}
}

/* Core of program */
void	shell(bool inline_mode)
{
	char	*line;
	t_term	*term;

	while (true)
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
		execution(&line, inline_mode);
		if (inline_mode == true)
			exit_shell(*get_exit_value(), NULL);
	}
}

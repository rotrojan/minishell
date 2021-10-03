/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/03 02:04:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*lexer_parser(char *line)
{
	t_token	*tok_lst;
	t_node	*ast;

	ast = NULL;
	tok_lst = NULL;
	if (build_tok_lst(line, &tok_lst) == true)
	{
		if (build_ast(&tok_lst, &ast) == false || tok_lst != NULL)
		{
			if (tok_lst != NULL)
				ft_dprintf(STDERR_FILENO, "\nminishell: syntax error near \
unexpected token `%s'\n", tok_lst->data);
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
		}
	}
	else if (*get_signal_on() != SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
	reset_history_data();
}

/* 
** Return line and protect inline mode of /dev/random, /dev/zero and /dev/null.
** inline_mode allows to handle the cases where minishell reads on stdin, such
** such as pipes and input reditrection (exp: echo echo toto | ./minishell).
*/
static char	*get_line(bool inline_mode)
{
	char	*line;

	line = NULL;
	if (inline_mode == false)
	{
		prompt();
		line = ft_readline();
	}
	else if (get_next_line(STDIN_FILENO, &line) == -1
		|| ft_striter(line, &ft_isprint) == 0)
		exit_shell(*get_exit_value(), NULL);
	return (line);
}

/* Core of program: get command line from input and execut it.*/
void	shell(bool inline_mode)
{
	char	*line;

	while (true)
	{
		set_signal_on(0);
		line = get_line(inline_mode);
		execution(line, inline_mode);
		if (inline_mode == true)
			exit_shell(*get_exit_value(), NULL);
	}
}

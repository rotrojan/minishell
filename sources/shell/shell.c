/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 16:17:55 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*lexer_parser(char *line)
{
	t_token	*tok_lst;
	t_node	*ast;
	t_error	error;

	ast = NULL;
	tok_lst = NULL;
	ast = NULL;
	error = No_error;
	if (build_tok_lst(line, &tok_lst, &error) == FALSE)
		display_error(error, &tok_lst);
	else
	{
		if (build_ast(&tok_lst, &ast) == FALSE)
		{
			if (tok_lst->type == Amp_tok)
				display_error(Amp_token, &tok_lst);
			else
				display_error(Unexpected_token, &tok_lst);
			clear_ast(&ast);
		}
	}
	clear_tokens(&tok_lst);
	return (ast);
}

/* Core of program */
void	shell(void)
{
	char			*line;
	t_node			*ast;

	ast = NULL;
	while (1)
	{
		prompt();
		line = input();
		if (line[0] != '\0')
		{
			put_in_history(line);
			ast = lexer_parser(line);
			exec_ast(ast);
			clear_ast(&ast);
		}
		else
		{
			ft_fprintf(STDERR_FILENO, "\n\r");
			gc_free(line);
		}
	}
}

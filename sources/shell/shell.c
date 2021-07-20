/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/20 16:25:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Function made for testing purposes. */
void	print_tokens(t_token **tok_lst)
{
	t_token	*current;

	current = *tok_lst;
	printf("\n");
	while (current)
	{
		if (current->type == Word_tok)
			printf("Word_tok ");
		else if (current->type == Pipe_tok)
			printf("Pipe_tok ");
		else if (current->type == Or_tok)
			printf("Or_tok ");
		else if (current->type == Amp_tok)
			printf("Amp_tok ");
		else if (current->type == And_tok)
			printf("And_tok ");
		else if (current->type == Semic_tok)
			printf("Semic_tok ");
		else if (current->type == Lesser_tok)
			printf("Lesser_tok ");
		else if (current->type == Dlesser_tok)
			printf("Dlesser_tok ");
		else if (current->type == Greater_tok)
			printf("Greater_tok ");
		else if (current->type == Dgreater_tok)
			printf("Dgreater_tok ");
		printf("(%s) -> ", current->data);
		current = current->next;
	}
	printf("%p\n", current);
}

/* Core of program */
void	shell(void)
{
	char	*line;
	t_token	*tok_lst;
	t_node	*ast;

	tok_lst = NULL;
	ast = NULL;
	while (1)
	{
		prompt();
		line = input();
		if (line[0] != '\0')
		{
			put_in_history(line);
			build_tok_lst(line, &tok_lst);
			/* print_tokens(&tok_lst); */
			/* printf("yolo\n"); */
			build_ast(&tok_lst, &ast);
			clear_ast(&ast);
			/* clear_tokens(&tok_lst); */
		}
		else
			gc_free(line);
		ft_fprintf(STDERR_FILENO, "\n\r");
	}
}

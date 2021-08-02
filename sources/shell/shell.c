/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/02 16:16:48 by rotrojan         ###   ########.fr       */
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
		else if (current->type == Oparenth_tok)
			printf("Oparenth_tok ");
		else if (current->type == Cparenth_tok)
			printf("Cparenth_tok ");
		printf("(%s) -> ", current->data);
		current = current->next;
	}
	printf("%p\n", current);
}

void	print_ast(t_node *ast)
{
	int	i;
	t_redirection	*current;

	if (ast->type == Simple_cmd)
	{
		i = 0;
		/* printf("\nCOMMAND"); */
		fflush(stdout);
		while (ast->content.simple_cmd.argv[i])
		{
			printf("\n%s", ast->content.simple_cmd.argv[i++]);
			fflush(stdout);
		}
		current = ast->content.simple_cmd.redirection;
		if (current != NULL)
		{
			printf("\n== redirections ==");
			fflush(stdout);
		}
		while (current != NULL)
		{
			if (current->type == Heredoc_redir)
			{
				printf("\nHereDoc\n%s", current->stream);
				fflush(stdout);
			}
			else if (current->type == Output_redir)
			{
				printf("\nOutput redirection\n%s", current->stream);
				fflush(stdout);
			}
			else if (current->type == Input_redir)
			{
				printf("\nInput redirection\n%s", current->stream);
				fflush(stdout);
			}
			else if (current->type == Append_output_redir)
			{
				printf("\nAppend Output redirection\n%s", current->stream);
				fflush(stdout);
			}

			current = current->next;
		}
	}
	else
	{
		print_ast(ast->content.child.left);
		if (ast->type == Pipe_node)
		{
			printf("\nPIPE");
			fflush(stdout);
		}
		else if (ast->type == And_node)
		{
			printf("\nAND");
			fflush(stdout);
		}
		else if (ast->type == Semic_node)
		{
			printf("\nSEMI COLON");
			fflush(stdout);
		}
		else if (ast->type == Or_node)
		{
			printf("\nOR");
			fflush(stdout);
		}
		print_ast(ast->content.child.right);
	}
}

void test()
{
	char *str[] = {
		"Any_chr",
		"Null_chr",
		"Space_chr",
		"Squote_chr",
		"Dquote_chr",
		"Less_chr",
		"Great_chr",
		"And_chr",
		"Semic_chr",
		"Pipe_chr",
		"Oparenth_chr",
		"Cparenth_chr"
	};

	unsigned char c = 0;
	while (c <= 127)
	{
		printf("%c = %s\n", c, str[get_chr_type(c)]);
		c++;
	}

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
			print_tokens(&tok_lst);
			/* if (build_ast(&tok_lst, &ast) == False) */
			/* { */
				/* if (tok_lst->type == Amp_tok) */
					/* display_error(Amp_token, &tok_lst); */
				/* else */
					/* display_error(Unexpected_token, &tok_lst); */
				/* clear_ast(&ast); */
			/* } */
			/* else */
				/* print_ast(ast); */
			clear_tokens(&tok_lst);
		}
		else
			gc_free(line);
		ft_fprintf(STDERR_FILENO, "\n\r");
	}
}

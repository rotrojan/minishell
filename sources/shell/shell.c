/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/25 12:33:03 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* Function made for testing purposes. */
void print_tokens(t_token **tok_lst)
{
	t_token *current;

	current = *tok_lst;
	printf("\n");
	while (current)
	{
		printf("%s -> ", current->data);
		current = current->next;
	}
	printf("%p\n", current);
}

/* Core of program */
void	shell(void)
{
	char	*line;
	t_token *tok_lst;

	while (1)
	{
		prompt();
		line = input();
		if (line[0] != '\0')
		{
			put_in_history(line);
			tok_lst = lexer_build(line);
			print_tokens(&tok_lst);

		}
		else
			gc_free(line);
		ft_fprintf(STDERR_FILENO, "\n\r");
	}
}

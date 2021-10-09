/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:49:27 by bigo              #+#    #+#             */
/*   Updated: 2021/10/09 18:08:37 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "minishell.h"

/*
** output_redirection.c
*/

int		output_redirection(char **args);

/*
** input_redirection.c
*/

int		heredoc_redirection(char const *stream, bool input_stream_has_quotes);
int		input_redirection(char const *stream);

/*
** heredoc.c
*/

char	*heredoc(char const *delimiter);

/*
** exec_redirections.c
*/

bool	arg_is_redirection(char *arg);
bool	exec_redirections(t_node *ast);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:49:27 by bigo              #+#    #+#             */
/*   Updated: 2021/10/08 00:40:26 by bigo             ###   ########.fr       */
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

int		heredoc_redirection(char const *stream);
int		input_redirection(char const *stream);

/*
** heredoc.c
*/

char	*heredoc(char const *delimiter);

/*
** exec_redirections.c
*/

bool	exec_redirections(t_node *ast);

#endif

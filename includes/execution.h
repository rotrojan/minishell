/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/16 04:43:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//	execution
void	exec_ast(t_node *ast, bool inline_mode);
void	exec_simple_cmd(t_simple_cmd simple_cmd);
int		run_binary(char **argv);
//		redirection
int		redirection(t_simple_cmd command);
void	close_redirections(t_redirection *redirection);
int		input_redirection(t_redirection *redirection);
int		output_redirection(t_redirection *redirection);
char	*heredoc(const char *delimiter);

#endif

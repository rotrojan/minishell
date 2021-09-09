/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/09 23:44:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//	execution
void	exec_ast(t_node *ast);
void	exec_simple_cmd(t_simple_cmd simple_cmd);
int		run_binarie(char **argv);
//		redirection
int		redirection(t_simple_cmd command);
int		input_redirection(t_redirection *redirection);
int		output_redirection(t_redirection *redirection);
char	*heredoc(const char *delimiter);

#endif

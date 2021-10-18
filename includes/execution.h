/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/18 17:21:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# define EXIT_EXEC_ERROR 126
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_C_VALUE 130
# define EXIT_SEGFAULT 139
# define EXIT_SYNTAX_ERROR 2

enum e_pipe
{
	Output,
	Input
};

t_IO_file	*get_io(void);
bool		*get_is_piped(void);
void		set_is_piped(bool value);
void		exec_ast(t_node *ast, bool inline_mode);
void		exec_list_cmd(t_node *ast);
void		exec_pipe(t_node *ast);
void		exec_simple_cmd(t_simple_cmd simple_cmd);
int			run_binary(char **argv);
int			*get_exit_value(void);
void		set_exit_value(int exit_value);

#endif

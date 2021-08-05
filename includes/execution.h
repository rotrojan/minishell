/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/05 03:04:42 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/*
** exec_ast.c
*/

void	exec_ast(t_node *ast);

/*
** exec_simple_cmd.c
*/

void	exec_simple_cmd(t_simple_cmd simple_cmd);

#endif

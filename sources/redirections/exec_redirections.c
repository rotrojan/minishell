/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:35:00 by bigo              #+#    #+#             */
/*   Updated: 2021/10/08 17:41:27 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_redirections_from_argv(char **args)
{
	int	i;

	i = 2;
	while (args[i] != NULL)
	{
		args[i - 2] = args[i];
		++i;
	}
	args[i - 2] = args[i];
}

static bool	arg_is_redirection(char *arg)
{
	return (ft_strcmp(">", arg) == 0 || ft_strcmp(">>", arg) == 0
		|| ft_strcmp("<", arg) == 0 || ft_strcmp("<<", arg) == 0);
}

static bool	redirections(char **args, int *fd_in, int *fd_out)
{
	if (ft_strcmp("<", *args) == 0)
	{
		if (*fd_in != STDIN_FILENO)
			close(*fd_in);
		*fd_in = input_redirection(*(args + 1));
		if (*fd_in == ERR)
			return (false);
	}
	else if (ft_strcmp("<<", *args) == 0)
	{
		if (*fd_out != STDOUT_FILENO)
			close(*fd_out);
		*fd_in = heredoc_redirection(*(args + 1));
		if (*fd_in == ERR)
			return (false);
	}
	else
	{
		*fd_out = output_redirection(args);
		if (*fd_out == ERR)
			return (false);
	}
	return (true);
}

static bool	open_redirections(char **argv, int *fd_in, int *fd_out)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (arg_is_redirection(argv[i]) == true)
		{
			if (redirections(&argv[i], fd_in, fd_out) == false)
				return (false);
			remove_redirections_from_argv(&argv[i]);
		}
		else
			++i;
	}
	return (true);
}

bool	exec_redirections(t_node *ast)
{
	if (ast->type == Simple_cmd)
	{
		return (open_redirections(ast->content.simple_cmd.argv,
				&ast->content.simple_cmd.fd_in,
				&ast->content.simple_cmd.fd_out));
	}
	else
	{
		if (exec_redirections(ast->content.child.left) == false)
			return (false);
		if (exec_redirections(ast->content.child.right) == false)
			return (false);
		return (true);
	}
}

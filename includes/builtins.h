/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:05:03 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/18 15:59:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

typedef struct s_IO_file
{
	int	input;
	int	output;
}	t_IO_file;

typedef struct s_builtins
{
	char	*name;
	int		(*function)(int, char **);
}			t_builtins;

int		run_builtin(int argc, char **argv, t_IO_file save);
void	close_io(t_IO_file save);
int		ft_env(int argc, char **argv);
int		ft_echo(int argc, char **argv);
int		pwd(int argc, char **argv);
int		ft_exit(int argc, char **argv);
int		cd(int argc, char **argv);
int		unset(int argc, char **argv);
int		export(int argc, char **argv);
int		export_get_len_var_name(char *arg);
char	*get_var_value(char *str, char *env_value);

#endif

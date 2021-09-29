/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:05:03 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/29 23:21:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_builtins
{
	char	*name;
	int		(*function)(int, char **);
}			t_builtins;

int	run_builtin(int argc, char **argv);
int	ft_env(int argc, char **argv);
int	ft_echo(int argc, char **argv);
int	pwd(int argc, char **argv);
int	ft_exit(int argc, char **argv);
int	cd(int argc, char **argv);
int	unset(int argc, char **argv);
int	export(int argc, char **argv);
int	display_env(void);

#endif

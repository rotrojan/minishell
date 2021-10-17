/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:59:32 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/17 14:25:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

typedef char	**t_env;

typedef enum e_os_name
{
	Darwin = 0,
	Linux = 1
}	t_os_name;

void	exit_shell(int status, char *message);
void	ft_dsleep(int time);
int		ft_fflush(int fd);
char	*ft_gethostname(void);
char	*getbinpath(const char *bin);
char	*ft_realpath(char const *path);
char	*extract_file(char *pathfile);
char	*extract_path(char const *pathfile);
char	*get_real_filepath(char const *filepath);
void	set_timeout(t_term *term, int timeout);
bool	init_term(void);
void	ignore_signals(void);
void	handle_signals(void);
int		*get_signum(void);
void	set_signum(int sig);
int		is_directory(char *bin_path);
bool	is_executable(char *bin_path);

/*
** env
*/

char	*ft_getenv(const char *name);
int		ft_inenv(const char *name);
int		ft_unsetenv(const char *name);
void	ft_setenv(const char *name, const char *value, int overwrite);
t_env	*get_shell_env(void);
int		env_len(t_env env);
int		init_shell_env(char *shell_name, t_env env);

#endif

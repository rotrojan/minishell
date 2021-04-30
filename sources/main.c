/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:20:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 19:49:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_term(void)
{
	int		ret;
	char	*term;

	term = getenv("TERM");
	if (term == NULL)
		ft_exit_error("getenv(): TERM not set in env.\n");
	ret = tgetent(NULL, term);
	if (ret < 1)
		ft_exit_error("tgetent(): missing or insufficient data for this term\n");
}

static char	*ft_getbinpath(char *bin)
{
	int			i;
	char		**paths;
	char		*bin_path;
	struct stat	buf;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i])
	{
		bin_path = ft_strjoin(paths[i], bin, "/");
		if (lstat(bin_path, &buf) == 0)
		{
			ft_free_arrays(paths);
			return (bin_path);
		}
		free(bin_path);
		i++;
	}
	ft_free_arrays(paths);
	return (NULL);
}

static char	*ft_gethostname(void)
{
	int			fd[2];
	pid_t		pid;
	char		*hostname;
	char		*bin_path;
	static char	*arg[] = {"cat", "/etc/hostname", NULL};

	hostname = NULL;
	bin_path = ft_getbinpath(arg[0]);
	if (!bin_path)
		ft_exit_error("ft_getbinpath(): No path found.\n");
	if (pipe(fd) == ERR)
		ft_exit_error(strerror(errno));
	pid = fork();
	if (pid == ERR)
		ft_exit_error(strerror(errno));
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(ft_getbinpath(arg[0]), arg, NULL);
		dup2(STDOUT_FILENO, fd[1]);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		get_next_line(fd[0], &hostname);
		close(fd[0]);
	}
	return (hostname);
}

static void	ft_prompt(void)
{
	int		i;
	char	*home;
	char	*pwd;
	char	*hostname;

	home = getenv("HOME");
	pwd = getenv("PWD");
	hostname = ft_gethostname();
	i = ft_strlen(home);
	ft_putstr(getenv("USER"));
	ft_putchar('@');
	ft_putstr(hostname);
	ft_putchar(':');
	if (!ft_strncmp(home, pwd, i))
	{
		ft_putchar('~');
		ft_putstr(&pwd[i]);
	}
	else
		ft_putstr(pwd);
	ft_putstr("> ");
	free(hostname);
}

static void	ft_shell(void)
{
	ft_prompt();
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	ft_init_term();
	ft_shell();
	return (EXIT_SUCCESS);
}

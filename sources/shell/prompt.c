/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:36:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/30 10:14:48 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	get_prompt_infos(void)
{
	char			*pwd;
	static int		init = false;
	static t_prompt	prompt;

	if (init == false)
	{
		if (OS == Linux)
			prompt.hostname = ft_gethostname();
		else
			prompt.hostname = NULL;
		init = true;
	}
	prompt.home = ft_getenv("HOME");
	prompt.user = ft_getenv("USERNAME");
	if (prompt.user == NULL)
		prompt.user = ft_getenv("USER");
	if (getcwd(prompt.pwd, SIZE_8B) == NULL)
	{
		pwd = ft_getenv("PWD");
		if (pwd == NULL)
			prompt.pwd[0] = '.';
		else
			ft_strcpy(prompt.pwd, pwd);
	}
	return (prompt);
}

static void	display_host(t_prompt prompt)
{
	if (prompt.user != NULL && prompt.hostname != NULL)
	{
		tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar_err);
		ft_dprintf(STDERR_FILENO, "%s%s@%s%s", KGRN, prompt.user,
			prompt.hostname, KNRM);
		tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar_err);
		ft_putchar_err(':');
	}
}

static void	display_pwd(t_prompt prompt)
{
	int	i;

	if (prompt.home != NULL)
		i = ft_strlen(prompt.home);
	tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar_err);
	if (prompt.home != NULL && ft_strncmp(prompt.home, prompt.pwd, i) == 0)
		ft_dprintf(STDERR_FILENO, "%s~%s%s", KBLU, &prompt.pwd[i], KNRM);
	else
		ft_dprintf(STDERR_FILENO, "%s%s%s", KBLU, prompt.pwd, KNRM);
	tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar_err);
	ft_dprintf(STDERR_FILENO, "> ");
}

/* Display prompt in format: user@hostname:pwd> on linux.
 pwd> on MacOS.*/
void	prompt(void)
{
	t_prompt		prompt;

	prompt = get_prompt_infos();
	if (*get_exit_value() != 0)
		ft_dprintf(STDERR_FILENO, "%s ✘ %s", KRED, KNRM);
	if (OS == Linux)
		display_host(prompt);
	display_pwd(prompt);
}

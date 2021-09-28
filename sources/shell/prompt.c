/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:36:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/28 23:04:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	get_prompt_infos(void)
{
	static int		init = false;
	static t_prompt	prompt;

	if (init == false)
	{
		prompt.home = ft_getenv("HOME");
		prompt.user = ft_getenv("USERNAME");
		if (prompt.user == NULL)
			prompt.user = ft_getenv("USER");
		if (OS == Linux)
			prompt.hostname = ft_gethostname();
		else
			prompt.hostname = NULL;
		init = true;
	}
	prompt.pwd = ft_getenv("PWD");
	if (prompt.pwd == NULL)
		prompt.pwd = ".";
	return (prompt);
}

/* Display prompt in format: user@hostname:pwd> on linux.
 pwd> on MacOS.*/
void	prompt(void)
{
	int				i;
	t_prompt		prompt;

	prompt = get_prompt_infos();
	i = ft_strlen(prompt.home);
	if (OS == Linux)
	{
		tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar_err);
		ft_dprintf(STDERR_FILENO, "%s%s@%s%s", KGRN, prompt.user,
			prompt.hostname, KNRM);
		tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar_err);
		ft_putchar_err(':');
	}
	tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar_err);
	if (!ft_strncmp(prompt.home, prompt.pwd, i))
		ft_dprintf(STDERR_FILENO, "%s~%s%s", KBLU, &prompt.pwd[i], KNRM);
	else
		ft_dprintf(STDERR_FILENO, "%s%s%s", KBLU, prompt.pwd, KNRM);
	tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar_err);
	ft_dprintf(STDERR_FILENO, "> ");
}

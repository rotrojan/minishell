/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:36:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/15 16:10:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	get_prompt_infos(void)
{
	static int		init = FALSE;
	static t_prompt	prompt;

	if (init == FALSE)
	{
		prompt.home = ft_getenv("HOME");
		prompt.user = ft_getenv("USERNAME");
		if (prompt.user == NULL)
			prompt.user = ft_getenv("USER");
		if (OS == Linux)
			prompt.hostname = ft_gethostname();
		else
			prompt.hostname = NULL;
		init = TRUE;
	}
	prompt.pwd = ft_getenv("PWD");
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
		tputs(tparm(tgetstr(COLOR_CAP, NULL), COLOR_GREEN), 1, ft_putchar_err);
		ft_fprintf(STDERR_FILENO, "%s@%s", prompt.user, prompt.hostname);
		tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar_err);
		ft_putchar_err(':');
	}
	tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar_err);
	tputs(tparm(tgetstr(COLOR_CAP, NULL), COLOR_BLUE), 1, ft_putchar_err);
	if (!ft_strncmp(prompt.home, prompt.pwd, i))
		ft_fprintf(STDERR_FILENO, "~%s", &prompt.pwd[i]);
	else
		ft_fprintf(STDERR_FILENO, "%s", prompt.pwd);
	tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar_err);
	ft_fprintf(STDERR_FILENO, "> ");
}

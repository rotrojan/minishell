/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:36:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/11 22:12:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	get_prompt_infos(enum e_os_name os_name)
{
	t_prompt	prompt;

	prompt.home = getenv("HOME");
	prompt.pwd = getenv("PWD");
	prompt.user = getenv("USER");
	if (os_name == Linux)
		prompt.hostname = ft_gethostname();
	else
		prompt.hostname = NULL;
	return (prompt);
}

void	prompt(void)
{
	int				i;
	t_prompt		prompt;
	enum e_os_name	os_name;

	os_name = getos();
	prompt = get_prompt_infos(os_name);
	i = ft_strlen(prompt.home);
	if (os_name == Linux)
	{
		tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar);
		tputs(tparm(tgetstr(COLOR_CAP, NULL), COLOR_GREEN), 1, ft_putchar);
		ft_printf("%s@%s", prompt.user, prompt.hostname);
		tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar);
		ft_putchar(':');
	}
	tputs(tgetstr(BOLD_CAP, NULL), 1, ft_putchar);
	tputs(tparm(tgetstr(COLOR_CAP, NULL), COLOR_BLUE), 1, ft_putchar);
	if (!ft_strncmp(prompt.home, prompt.pwd, i))
		ft_printf("~%s", &prompt.pwd[i]);
	else
		ft_printf("%s", prompt.pwd);
	tputs(tgetstr(RESET_CAP, NULL), 1, ft_putchar);
	ft_printf("> ");
	gc_free(prompt.hostname);
}

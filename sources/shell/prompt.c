/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:36:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/20 21:04:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	get_prompt_infos(void)
{
	t_prompt	prompt;

	prompt.home = ft_getenv("HOME");
	prompt.pwd = ft_getenv("PWD");
	prompt.user = ft_getenv("USER");
	if (OS == Linux)
		prompt.hostname = ft_gethostname();
	else
		prompt.hostname = NULL;
	return (prompt);
}

void	prompt(void)
{
	int				i;
	t_prompt		prompt;

	prompt = get_prompt_infos();
	i = ft_strlen(prompt.home);
	if (OS == Linux)
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

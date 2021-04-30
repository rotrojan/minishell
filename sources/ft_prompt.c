/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:36:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 00:47:37 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt(void)
{
	int			i;
	t_prompt	prompt;
	char		*color_cap;
	char		*bold_cap;

	color_cap = tgetstr("AF", NULL);
	bold_cap = tgetstr("md", NULL);
	prompt.home = getenv("HOME");
	prompt.pwd = getenv("PWD");
	prompt.hostname = ft_gethostname();
	i = ft_strlen(prompt.home);
	tputs(tparm(color_cap, COLOR_GREEN), 1, ft_putchar);
	tputs(bold_cap, 1, ft_putchar);
	ft_printf("%s@%s:", getenv("USER"), prompt.hostname);
	tputs(tparm(color_cap, COLOR_BLUE), 1, ft_putchar);
	if (!ft_strncmp(prompt.home, prompt.pwd, i))
		ft_printf("~%s", &prompt.pwd[i]);
	else
		ft_printf("%s", prompt.pwd);
	ft_printf("> ");
	free(prompt.hostname);
}

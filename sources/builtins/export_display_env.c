/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_display_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo </var/spool/mail/bigo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:57:42 by bigo              #+#    #+#             */
/*   Updated: 2021/09/10 22:03:19 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	display_env(void)
{
	int		i;
	t_env	*env;
	int		index_equalsign;

	i = 0;
	env = get_shell_env();
	while ((*env)[i])
	{
		ft_putstr("export ");
		if (ft_strchr((*env)[i], '=') != NULL)
		{
			index_equalsign = ft_strchr((*env)[i], '=') - (*env)[i];
			write(STDOUT_FILENO, (*env)[i], index_equalsign);
			ft_printf("=\"%s\"\n", (*env)[i] + index_equalsign + 1);
		}
		else
			ft_printf("%s\n", (*env)[i]);
		i++;
	}
	return (0);
}

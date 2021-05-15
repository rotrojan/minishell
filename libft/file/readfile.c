/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 05:30:40 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/14 03:47:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	readfile(int fd)
{
	int		ret;
	char	*line;
	t_list	*lines_lst;

	ret = 1;
	line = NULL;
	lines_lst = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (NULL);
		if (ret > 0)
			ft_list_push_back(&lines_lst, (void *)line);
	}
	return (ft_list_to_array(&lines_lst));
}

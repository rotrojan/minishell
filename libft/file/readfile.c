/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 05:30:40 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 18:07:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*readfile(int fd)
{
	int		len;
	int		ret;
	char	*file;
	char	buff[FBUFFER_SIZE];

	file = NULL;
	while (1)
	{
		ft_bzero(buff, FBUFFER_SIZE);
		ret = read(fd, buff, FBUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		if (ret == 0)
			return (file);
		len = ft_strlen(file);
		file = ft_realloc(file, sizeof(char) * (len + ret));
		ft_strcpy(&file[len], buff);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 05:41:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/01 00:47:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_entry(struct dirent *entry, t_list	**list, char *path)
{
	if (ft_strcmp(path, "./") == 0)
		ft_list_push_back(list, ft_strdup(entry->d_name));
	else
		ft_list_push_back(list, ft_strjoin(path, entry->d_name, ""));
}

static char	**get_entry(DIR *directory, char **path, char *file)
{
	t_list			*list;
	struct dirent	*entry;

	list = NULL;
	while (true)
	{
		entry = readdir(directory);
		if (entry == NULL)
		{
			gc_free((void **)path);
			closedir(directory);
			return (ft_list_to_array(&list));
		}
		if (match(entry->d_name, file) == 1)
			add_entry(entry, &list, *path);
	}
}

char	**wildcard(char *pathfile)
{
	char	*file;
	char	*path;
	DIR		*directory;

	file = extract_file(pathfile);
	path = extract_path(pathfile);
	directory = opendir(path);
	if (directory == NULL)
	{
		gc_free((void **)&path);
		return (NULL);
	}
	return (get_entry(directory, &path, file));
}

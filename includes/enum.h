/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:13:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/08/05 02:58:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_os_name
{
	Darwin = 0,
	Linux = 1
}	t_os_name;

typedef enum e_error
{
	No_error,
	Cmd_not_found,
	Bad_substitution,
	Unexpected_token,
	Unexpected_eof,
	Amp_token,
	NB_ERRORS
}	t_error;

enum e_fork
{
	Child,
	Parent
};

enum e_pipe
{
	Output,
	Input
};

#endif

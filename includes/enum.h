/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:13:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/11 22:14:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_token_type
{
	Or,
	And,
	Pipe,
	Space,
	Literal,
	Variable,
	Backslash,
	Semicolon,
	Simple_quote,
	Double_quote,
	Redirection_left,
	Redirection_right,
};

enum	e_os_name
{
	Darwin,
	Linux
};

#endif

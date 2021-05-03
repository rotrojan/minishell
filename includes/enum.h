/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:13:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/03 15:33:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_token_type
{
	OR,
	AND,
	PIPE,
	SPACE,
	LITERAL,
	VARIABLE,
	BACKSLASH,
	SEMICOLON,
	SIMPLE_QUOTE,
	DOUBLE_QUOTE,
	REDIRECTION_LEFT,
	REDIRECTION_RIGHT,
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:03:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/03 15:56:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# define FBUFFER_SIZE 4096
# define BASE_16L "0123456789abcdef"
# define BASE_16U "0123456789ABCDEF"

typedef struct s_fbuffer
{
	int		i;
	char	buffer[FBUFFER_SIZE];
}			t_fbuffer;

typedef struct s_fconvert
{
	char	type;
	void	(*function)(t_fbuffer *, va_list);
}			t_fconvert;

char		*format(char const *string, ...);
char		*vformat(char const *string, va_list ap);
void		convert_percent(t_fbuffer *format, va_list ap);
void		convert_c(t_fbuffer *format, va_list ap);
void		convert_s(t_fbuffer *format, va_list ap);
void		convert_d(t_fbuffer *format, va_list ap);
void		convert_i(t_fbuffer *format, va_list ap);
void		convert_x(t_fbuffer *format, va_list ap);
void		convert_X(t_fbuffer *format, va_list ap);

#endif

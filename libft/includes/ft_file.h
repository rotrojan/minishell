/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:06:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 23:34:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

int		ft_putchar(int c);
int		ft_putstr(char const *s);
int		ft_fputstr(int fd, char const *s);
void	ft_putnbr(int nb);
int		get_next_line(int fd, char **line);
int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);

#endif

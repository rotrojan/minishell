/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:06:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 21:04:26 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

int		ft_putchar(int c);
int		ft_putchar_fd(int c, int fd);
int		ft_putchar_err(int c);
int		ft_putstr(char const *s);
int		ft_putstr_fd(char const *s, int fd);
void	ft_putnbr(int nb);
int		get_next_line(int fd, char **line);
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
char	*readfile(int fd);

#endif

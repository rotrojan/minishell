/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:06:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/03 16:12:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

typedef char	**t_file;

int		ft_putchar(int c);
int		ft_putchar_err(int c);
int		ft_putstr(char const *s);
int		ft_putstr_fd(int fd, char const *s);
void	ft_putnbr(int nb);
int		get_next_line(int fd, char **line);
int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_vfprintf(int fd, const char *format, va_list ap);
char	**readfile(int fd);
void	free_file(t_file file);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:06:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/24 19:13:07 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

typedef char **t_file;

int		ft_putchar(int c);
int		ft_putchar_err(int c);
int		ft_putstr(char const *s);
int		ft_fputstr(int fd, char const *s);
void	ft_putnbr(int nb);
int		get_next_line(int fd, char **line);
int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
char	**readfile(int fd);
void	free_file(t_file file);

#endif

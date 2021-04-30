/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:06:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 21:06:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

int		ft_putchar(int c);
int		ft_putstr(char const *s);
int		ft_fputstr(int fd, char const *s);
void	ft_putnbr(int nb);
int		get_next_line(int fd, char **line);

#endif

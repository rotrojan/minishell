/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 04:04:54 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 04:15:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSTEM_H
# define FT_SYSTEM_H

# ifdef __linux__

#  define TTY_PATH "/dev/pts/"

# elif __APPLE__

#  define TTY_PATH "/dev/ttys00"

# endif

void	debug(int tty_id, char *str, ...);

#endif

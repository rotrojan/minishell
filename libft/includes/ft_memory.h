/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:25:40 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/12 17:23:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include "libft.h"

# define SIZE_16B 65536
# define SIZE_12B 4096
# define SIZE_11B 2048
# define SIZE_10B 1024
# define SIZE_8B 256

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_realloc(void *ptr, size_t size);

#endif

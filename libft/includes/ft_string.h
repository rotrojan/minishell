/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:20:37 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/21 19:51:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

int		ft_strlen(const char *s);
int		ft_isnumber(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
char	**ft_split(char const *str, char c);
void	ft_free_arrays(char **arrays);
char	*ft_strjoin(char const *s1, char const *s2, char const *sep);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_isalnum(int c);
void	ft_strdel(char *s);
int		ft_iscntrl(int c);
int		ft_putxchar(int c, int x);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:56 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 00:57:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

// system
char	*ft_gethostname(void);
char	*getbinpath(char *bin);
pid_t	ft_getpid(void);

void	prompt(void);
void	shell(void);

void	handle_signals(void);

// tokens
t_token	*create_token(int value);
void	print_tokens(t_token *tokens);
void	insert_token(t_token **tokens, t_cursor *cursor, int value);
void	clear_tokens(t_token **tokens);

#endif

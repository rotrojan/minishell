/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:56 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/04 14:36:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

// system
char	*ft_gethostname(void);
char	*getbinpath(char *bin);

void	prompt(void);
void	shell(void);

void	handle_signals(void);

t_token	*create_token(int value);
void	print_tokens(t_token *tokens);
t_token	*insert_token(t_token **tokens, t_cursor cursor, int value);

#endif

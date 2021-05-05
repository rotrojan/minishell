/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:56 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 18:15:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

//	system
char	*ft_gethostname(void);
char	*getbinpath(char *bin);
pid_t	ft_getpid(void);
void	handle_signals(void);
void	exit_shell(int status, char *message);
char	*pipe_exec(char *bin_path, char **arg);

//	terminal
void	init_term(void);
t_term	*getterm(void);

//	shell
void	shell(void);
void	prompt(void);
t_token	*input(void);

//	lexing
t_token	*create_token(int value);
void	print_tokens(t_token *tokens);
void	insert_token(t_token **tokens, t_cursor *cursor, int value);
void	clear_tokens(t_token **tokens);

#endif

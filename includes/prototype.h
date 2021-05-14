/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:56 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/14 01:10:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

//	system
char			*ft_gethostname(void);
enum e_os_name	getos(void);
char			*getbinpath(char *bin);
pid_t			ft_getpid(void);
void			handle_signals(void);
void			exit_shell(int status, char *message);
char			**pipe_exec(char *bin_path, char **arg);

//	terminal
void			init_term(void);
t_term			*getterm(void);
t_axe			get_cursor_pos(void);
int				ft_getch(void);
void			backspace_key(t_cursor *cursor);
void			left_arrow_key(t_cursor *cursor);
void			right_arrow_key(t_cursor *cursor);
void			delete_key(t_cursor *cursor);

//	shell
void			shell(void);
void			prompt(void);
t_token			*input(void);
void			init_shell_env(t_env *env);
t_env			*get_shell_env(void);

//	lexing
t_token			*create_token(int value);
void			print_tokens(t_token *tokens);
void			insert_token(t_cursor *cursor, int value);
void			clear_tokens(t_token **tokens);
int				tokens_len(t_token *tokens);
t_token			*tokens_head(t_cursor *cursor);

#endif

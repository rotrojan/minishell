/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:56 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/15 20:30:49 by lucocozz         ###   ########.fr       */
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
t_inchar		*input(void);
void			init_shell_env(t_env *env);
t_env			*get_shell_env(void);
void			put_in_history(t_inchar *inchars);

//	lexing
t_inchar		*create_inchar(int value);
void			print_inchars(t_inchar *inchars);
void			insert_inchar(t_cursor *cursor, int value);
void			clear_inchars(t_inchar **inchars);
int				inchars_len(t_inchar *inchars);
t_inchar		*inchars_head(t_cursor *cursor);

#endif

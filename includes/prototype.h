/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:56 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 04:35:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

//	system
enum e_os_name	getos(void);
pid_t			ft_getpid(void);
void			handle_signals(void);
char			*ft_gethostname(void);
char			*getbinpath(char *bin);
void			exit_shell(int status, char *message);
char			**pipe_exec(char *bin_path, char **arg);

//	terminal
int				ft_getch(void);
t_term			*getterm(void);
void			init_term(void);
t_axe			get_cursor_pos(void);
void			end_key(t_cursor *cursor);
void			home_key(t_cursor *cursor);
void			delete_key(t_cursor *cursor);
void			ctrl_l_key(t_cursor *cursor);
void			backspace_key(t_cursor *cursor);
void			left_arrow_key(t_cursor *cursor);
void			right_arrow_key(t_cursor *cursor);
void			cursor_move_left(t_cursor *cursor);
void			cursor_move_right(t_cursor *cursor);

//	shell
void			shell(void);
void			prompt(void);
char			*input(void);
t_env			*get_shell_env(void);
void			init_shell_env(t_env *env);
//		history
t_history_data	*get_history(void);
void			free_history(void);
t_history_data	*init_history(void);
void			put_in_history(char *line);
t_history		*create_history(char *line);
void			history_get_up(t_cursor *cursor);
void			push_front_history(t_history **history, char *line);
//		inchar
t_inchar		*create_inchar(int value);
t_inchar		*line_to_inchars(char *line);
int				inchars_len(t_inchar *inchars);
t_inchar		*inchars_head(t_cursor *cursor);
t_inchar		*inchars_queue(t_cursor *cursor);
void			print_inchars(t_inchar *inchars);
void			free_inchars(t_inchar **inchars);
char			*inchars_to_line(t_inchar *inchars);
void			insert_inchar(t_cursor *cursor, int value);
void			push_back_inchars(t_inchar **inchars, int value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:13:40 by rotrojan          #+#    #+#             */
/*   Updated: 2021/10/18 22:08:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"
# define BOLD_CAP "md"
# define RESET_CAP "me"
# define HISTORY_FILE ".minishell_history"
# define EOL 0

typedef struct s_history
{
	char				*line;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct s_history_data
{
	char				*input;
	struct s_history	*data;
	struct s_history	*tmp_nav;
}						t_history_data;

void			shell(bool inline_mode);
void			prompt(void);
char			*ft_readline(void);
int				*get_line_count(void);
int				increase_line_count(void);

/*
** history
*/

t_history_data	*get_history(void);
void			free_history(void);
void			reset_history_data(void);
t_history_data	*init_history(void);
void			put_in_history(char *line);
t_history		*create_history(char *line);
void			history_get_up(t_cursor *cursor);
void			history_get_down(t_cursor *cursor);
void			display_history(t_cursor *cursor, char *line);
void			push_front_history(t_history **history, char *line);

/*
** inchar
*/

t_inchar		*create_inchar(int value);
t_inchar		*line_to_inchars(char *line);
int				inchars_len(t_cursor *cursor, bool go_head);
t_inchar		*inchars_head(t_cursor *cursor);
t_inchar		*inchars_queue(t_cursor *cursor);
void			print_inchars(t_inchar *inchars);
void			free_inchars(t_cursor *cursor);
char			*inchars_to_line(t_cursor *cursor);
void			insert_inchar(t_cursor *cursor, int value);
void			push_back_inchars(t_inchar **inchars, int value);

#endif

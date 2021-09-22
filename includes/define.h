/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 02:27:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/22 22:26:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define _XOPEN_SOURCE 700

# ifdef __linux__

#  define OS 1

# elif __APPLE__

#  define OS 0

# endif

# define SIGWINCH 28

# define EOL 0
# define NB_SPECIAL_KEY 6
# define PATH_MAX 256

# define CTRL_C 2
# define CTRL_D 4
# define DELETE 8
# define TAB 9
# define CTRL_L 12
# define ESC 27
# define BACKSPACE 127

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define BOLD_CAP "md"
# define RESET_CAP "me"

# define HISTORY_FILE ".minishell_history"

# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_C_VALUE 130
# define EXIT_SYNTAX_ERROR 2

#endif

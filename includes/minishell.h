/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/12 20:23:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>     // printf, perror
# include <stdlib.h>    // malloc, free, exit, getenv
# include <unistd.h>    // write, access, close, fork, execve, dup, dup2, pipe, getcwd, chdir, unlink, isatty, ttyname, ttyslot, ioctl, isatty
# include <signal.h>    // signal,sultant discovere sigaction, sigemptyset, sigaddset, kill, fork
# include <sys/types.h> // definitions of data, like pid_t, gid_t, getcwd, 
# include <sys/wait.h>  // wait, waitpid, wait3, wait4
# include <sys/stat.h>  // stat, lstat, fstat
# include <fcntl.h>     // open
# include <string.h>    // strerror
# include <errno.h>     // perror
# include <dirent.h>    // opendir, readdir, closedir
# include <termios.h>   // tcsetattr, tcgetattr
# include <termcap.h>   // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <readline/readline.h>     // readline
# include <readline/history.h>      // rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history




#endif
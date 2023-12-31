/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina.silva <carolina.silva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/05 18:33:35 by carolina.si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

//TODO: suggestion - Use enum for STATES 
//-> ex.: enum states { START, IN_WORD, IN_STRING } state = START;

typedef struct s_data
{
	char			**cmd;
	char			**cmd_args;
	char			**heredoc;
	struct s_rdct	**rdct;
	char			**env;
	struct s_data	*next;
}					t_data;

typedef struct s_rdct
{
	char			*redirect;
	char			*file;
	struct s_rdct	*next;
}					t_rdct;

void				init_prompt(void);
int					is_builtins(char *check);
t_data				*create_data_list(int argc, char **argv);
void				ft_echo(t_data *data);
void				welcome(void);

#endif

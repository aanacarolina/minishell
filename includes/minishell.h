/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/22 21:02:42 by anacaro3         ###   ########.fr       */
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

typedef struct s_data
{
	char			**command;
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

void	init_prompt(void);
int		is_builtins(char *check);
void	ft_echo(char **args);

#endif

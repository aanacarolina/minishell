/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:59:04 by anacaro3          #+#    #+#             */
/*   Updated: 2023/09/22 21:48:59 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// echo = Output the args, separated by spaces, terminated with a newline.
// option -n = do not output the trailing newline

// TODO: print args
// TODO if arg[1] == '-n ' ignore spaces
// (char *args) -> t_data *prt (struct de cmd a parte da flag / cmd_args)
// TODO: tratar expansao 
// TODO: devolver prompt

void	ft_echo(char **args)  
{
	int	i;

	i = 0;
	{
		while (args)
		{
			printf("%s ", args[i]);
			i++;
		}
        printf("\n");
	}
}

// int	main(void)
// {
// 	char **argzin;

//     argzin[0] = "echo";
//     argzin[1] = "oi";
//     ft_echo(argzin);
// 	return (0);
// }

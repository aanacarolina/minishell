/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina.silva <carolina.silva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:59:04 by anacaro3          #+#    #+#             */
/*   Updated: 2023/09/23 00:07:47 by carolina.si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// echo = Output the args, separated by spaces, terminated with a newline.
// option -n = do not output the trailing newline

// TODO: print args
// TODO if arg[1] == '-n ' ignore spaces
// (char *args) -> t_data *prt (struct de cmd a parte da flag / cmd_args)
// TODO: tratar expansao (no expansion)
// TODO: devolver prompt

void	ft_echo(t_data **data)
{
	int	i;
	t_data **temp;

	i = 0;
	temp = data;
	while ((*temp)->cmd_args[i] != NULL)
	{
		printf("%s ", (*temp)->cmd_args[i]);
		i++;
	}
	if (ft_strncmp((*data)->cmd[1], "-n", 3) != 0)
		printf("\n");
}


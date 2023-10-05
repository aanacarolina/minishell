/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina.silva <carolina.silva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:59:04 by anacaro3          #+#    #+#             */
/*   Updated: 2023/10/05 18:53:18 by carolina.si      ###   ########.fr       */
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
// TODO remove last space %s

void	ft_echo(t_data *data)
{
	int		i;
	t_data	*temp;

	i = 0;
	temp = data;
	printf("%s", temp->cmd_args[i]);
	i++;
	while (temp->cmd_args[i+1])
	{
		printf(" %s", temp->cmd_args[i]);
		i++;
	}
	if (data->cmd[1] == NULL)
		printf("\n");
}

// TODO - EXIT STATUS = The echo utility exits 0 on success,
// and >0 if an error occurs.
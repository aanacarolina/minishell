/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 14:29:23 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void DEBUG_printlist(t_data *args)
{
	t_data *temp;
	int i;

	i = 0;
	if (args == NULL)
	{
		printf("this list is NULL");
		return;
	}
	temp = args;
	printf("node [%i]: data: [%s]\n", i, temp->cmd_args[i]);
	i++;
	while (temp != NULL)
	{
		temp = temp->cmd_args[i];
		if (temp != NULL)
		{
			printf("node [%i]: data: [%s]\n", i, temp->cmd_args[i]);
			i++;
		}
	}
}

// TODO: verificar se precisa msg de erro ou so encerrar?
int	main(int argc, char *argv[])
{

	(void)argv;
	//(void)envp;
	if (argc < 1)
		return (1);
	// init_prompt();
	cmd_args_array(argc, argv);
	t_data *argzins = args_to_list(argc, argv);
	DEBUG_printlist(argzins);
	//ft_echo(argzins);
	return (0);
}

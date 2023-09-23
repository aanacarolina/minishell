/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 20:21:50 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_list(t_data *head)
{
	t_data	*current;

	current = head;
	while (current != NULL)
	{
		printf("cmd: %s\n", *current->cmd);
		printf("cmd_args: %s\n", *current->cmd_args);
		current = current->next;
	}
}

// TODO: verificar se precisa msg de erro ou so encerrar?
int	main(int argc, char *argv[])
{
	t_data	*argzins;

	//(void)argv;
	//(void)envp;
	if (argc < 1)
		return (1);
	// init_prompt();
	argzins = create_data_list(argc, argv);
	//print_list(argzins);
	// ft_echo(argzins);
	return (0);
}

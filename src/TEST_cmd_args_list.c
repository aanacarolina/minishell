/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_cmd_args_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:49:17 by anacaro3          #+#    #+#             */
/*   Updated: 2023/09/23 17:20:54 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

//create node vai receber a struct inteira
t_data	*create_node(t_data )
{
	t_data	*new_node;

	new_node = (t_data *)malloc(sizeof(t_data));
	//if error
	new_node->cmd = cmd;
	new_node->cmd_args = cmd_args;
	new_node->next = NULL;
	return (new_node);
}

//TODO separar funcao do arrays de cmd
char	*cmd_arr(int argc, char **argv)


//TODO separar funcao do arrays de cmd_args
char	*cmd_args_arr(int argc, char **argv)


t_data	*create_tdata_list(int argc, char **argv)
{
	t_data	*head;
	t_data	*current;
	char	**cmd;
	char	**cmd_args;
	int		i;
	int		j;

	head = NULL;
	current = NULL;
	cmd = NULL;
	cmd_args = NULL;
	i = 2;
	j = 0;
	
	
	current = head;
	cmd[0] = argv[1]; //nome do builtin
	if (ft_strncmp(argv[2], "-n", 3) == 0)  //se tiver flag
	{
		cmd[1] = argv[i]; //i ta valendo 2 ("./prog", "builtin-name", "option" <-(so serve pra echo), "str1", "str2", "str3", NULL) 
		// isso so pra teste, dps nao vai ter nome do programa e ai diminuir os indices
		i++;
	}
	else
	{
		cmd_args[j] = argv[i];
		i++;
	}
	while (i < argc)
	{
		current->cmd_args[j] = argv[i];
		i++;
		j++;
	}
	current->cmd_args[j] = NULL;
	head = create_node(cmd, cmd_args);
	return (head);
}

/*
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
}*/
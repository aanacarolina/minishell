/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_cmd_args_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:49:17 by anacaro3          #+#    #+#             */
/*   Updated: 2023/09/24 15:00:14 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

// TODO separar funcao do arrays de cmd
char	*cmd_arr(char **argv)
{
	char	*cmd;

	cmd = ft_calloc(3, sizeof(char *));
	if (!cmd)
		return (NULL);
	cmd[0] = *argv[1];
	if (ft_strncmp(argv[2], "-n", 3) == 0)
		cmd[1] = *argv[2];
	//cmd[2] = NULL;
	return (cmd);
}

// TODO separar funcao do arrays de cmd_args
char	*cmd_args_arr(int argc, char **argv)
{
	int		i;
	int		j;
	char	*cmd_args;

	cmd_args = calloc(argc - 1, sizeof(char *)); // qty tem que saber se teve flag
	if (!cmd_args)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		cmd_args[j] = *argv[i];
		i++;
		j++;
	}
	//j++;
	// cmd_args[j] = NULL;
	return (cmd_args);
}

// create node vai receber a struct parseada, na realidade
t_data	*create_node(int argc, char **argv)
{
	t_data	*new_node;

	new_node = calloc(1, sizeof(t_data));
	if (!new_node)
		return (NULL);
	*new_node->cmd = cmd_arr(argv);
	*new_node->cmd_args = cmd_args_arr(argc, argv);
	new_node->next = NULL;
	return (new_node);
}

//por enquanto so cria o primeiro node - casos sem pipe e um cmd só
t_data	*create_data_list(int argc, char **argv)
{
	t_data	*head;
	int		i;

	i = 1;
	head = create_node(argc, &argv[i]);
	return (head);
}

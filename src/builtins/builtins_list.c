/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina.silva <carolina.silva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:49:17 by anacaro3          #+#    #+#             */
/*   Updated: 2023/10/05 18:36:44 by carolina.si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: handle expansion
// creates array to populate t_data cmd_arr
char	**cmd_arr(char **argv)
{
	char	**cmd;

	cmd = ft_calloc(3, sizeof(char *));
	if (!cmd)
		return (NULL);
	cmd[0] = ft_strdup(argv[1]);
	if (ft_strncmp(argv[1], "-n", 3) == 0)
	{
		cmd[1] = ft_strdup(argv[1]);
		cmd[2] = NULL;
	}
	else
		cmd[1] = NULL;
	return (cmd);
}

// creates array to populate t_data cmd_args_arr
char	**cmd_args_arr(int argc, char **argv)
{
	int		i;
	int		j;
	char	**cmd_args;

	cmd_args = calloc(argc - 2, sizeof(char *));
	if (!cmd_args)
		return (NULL);
	i = 1;
	j = 0;
	if (ft_strncmp(argv[1], "-n", 3) == 0)
		i++;
	while (i < argc)
	{
		cmd_args[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	cmd_args[++j] = NULL;
	return (cmd_args);
}

// create node vai receber a struct parseada, qdo parser ok
t_data	*create_node(int argc, char **argv)
{
	t_data	*new_node;

	new_node = ft_calloc(1, sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->cmd = cmd_arr(argv);
	new_node->cmd_args = cmd_args_arr(argc, argv);
	new_node->next = NULL;
	return (new_node);
}

// por enquanto so cria o primeiro node, pois
// casos sem pipe é um cmd só
t_data	*create_data_list(int argc, char **argv)
{
	t_data	*head;
	int		i;

	i = 1;
	head = create_node(argc, &argv[i]);
	return (head);
}

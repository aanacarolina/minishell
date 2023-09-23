/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_cmd_args_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:49:17 by anacaro3          #+#    #+#             */
/*   Updated: 2023/09/23 14:30:24 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cmd_args_array(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arr_args;

	arr_args = calloc(argc - 1, sizeof(t_data));
	i = 1;
	j = 0;
	while (i < argc)
	{
		arr_args[j] = *argv[i];
		i++;
		j++;
	}
	return (arr_args);
}

t_data	*create_node(char **cmd_args, t_data *next)
{
	t_data	*node;
	cmd_args = 
	// node = (t_data){ NULL };
	node = calloc(1, sizeof(t_data));
	// node->cmd = "-n";
	node->cmd_args = cmd_args;
	node->next = next;
	return (node);
}
// inserts a node(new_last_node) at the end of a list(head)
void	insert_tail(t_data *start, t_data *new_last_node)
{
	t_data	*temp;

	if (start->next == NULL)
	{
		start->next = new_last_node;
	}
	else
	{
		temp = start->next;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_last_node;
	}
}

// creates a llist from arguments
t_data	*args_to_list(int argc, char **argv)
{
	int		i;
	t_data	*head;
	t_data	*new_node;

	head = create_node(argv, NULL);
	i = 2;
	while (i != argc)
	{
		new_node = create_node(argv, NULL);
		insert_tail(head, new_node);
		i++;
	}
	return (head);
}

// // This function frees the stack.
// void	free_stack(t_data **stack)
// {
// 	t_data	*tmp;

// 	if (!stack)
// 		return ;
// 	while (*stack)
// 	{
// 		tmp = (*stack)->next;
// 		(*stack)->data = 0;
// 		free(*stack);
// 		*stack = tmp;
// 	}
// }
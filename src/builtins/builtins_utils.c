/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:27:23 by anacaro3          #+#    #+#             */
/*   Updated: 2023/09/22 21:25:30 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtins(char *check)
{
	if (ft_strncmp(check, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(check, "cd", 3) == 0)
		return (2);
	if (ft_strncmp(check, "pwd", 4) == 0)
		return (3);
	if (ft_strncmp(check, "export", 7) == 0)
		return (4);
	if (ft_strncmp(check, "unset", 6) == 0)
		return (5);
	if (ft_strncmp(check, "env", 4) == 0)
		return (6);
	if (ft_strncmp(check, "exit", 5) == 0)
		return (7);
	else
		return (0);
}

// void	call_builtins(t_data *ptr)
// {
// 	if (is_builtins(ptr->cmd[0]) == 1)
// 		ft_echo(ptr);
// 	if (is_builtins(ptr->cmd[0]) == 2)
// 		ft_cd(ptr);
// 	if (is_builtins(ptr->cmd[0]) == 3)
// 		ft_pwd(ptr);
// 	if (is_builtins(ptr->cmd[0]) == 4)
// 		ft_export(ptr);
// 	if (is_builtins(ptr->cmd[0]) == 5)
// 		ft_unset(ptr);
// 	if (is_builtins(ptr->cmd[0]) == 6)
// 		ft_env(ptr);
// 	if (is_builtins(ptr->cmd[0]) == 7)
// 		ft_exit(ptr);
// 	else
// 		printf("Them, all, eventually, went to shit");
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:18:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/20 22:50:33 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// *env_var; // variável de ambiente que quiser acessar
// env_value = getenv(env_var); // Usando getenv para 
// obter o valor da variável de ambiente
// perror("execve"); // Se chegarmos aqui, algo deu errado com execve
// if (child_pid > 0) // Verifica se este é o processo pai

char	**cmd_args(char *path)
{
	char	**command_args;

	command_args = malloc(sizeof(char *) * 4);
	command_args[0] = path;
	command_args[1] = ">";
	command_args[2] = "ola";
	command_args[3] = NULL;
	return (command_args);
}

int	if_child(char	*env_var, char	*path)
{
	if (getenv(env_var) == NULL)
	{
		perror("getenv");
		return (1);
	}
	printf("Executando filho.\n");
	printf("env_value: %s\n", getenv(env_var));
	execve(path, cmd_args(path), &env_var);
	perror("execve");
	exit(1);
}

int	main(void)
{
	char	*path;
	char	*env_var;
	int		status;
	pid_t	child_pid;

	env_var = "USER";
	path = "/bin/cat";
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (child_pid == 0)
		if_child(env_var, path);
	else
	{
		if (child_pid > 0)
			printf("Executando o programa pai...\n");
		waitpid(child_pid, &status, 0);
		printf("-Execução do programa filho concluída.\n");
	}
	return (0);
}

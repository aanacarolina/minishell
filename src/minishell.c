/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/15 21:11:44 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;

	(void)argv;
	(void)envp;
	if (argc != 1) // TODO: verificar se precisa msg de erro ou so encerrar?
		return (1);
	while (1)
	{
		input = readline("prompt$ ");
		if (input == NULL)
		{
			printf("\n");
			break ;
		}
		if (input[0] != '\0')
		{
			// Adiciona o comando à história se não estiver vazio
			// TODO: confirmar se serve como seta pra cima
			add_history(input);
			// Agora 'input' contém o comando digitado pelo usuário
			printf("That's what she said: %s\n", input);
		}
		free(input);
		input = NULL;
	}
	return (0);
}

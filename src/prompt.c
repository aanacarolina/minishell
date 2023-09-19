/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:38:38 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/18 21:52:48 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// add_history - Adiciona o comando à história se não estiver vazio
// apos utilizar a func a var 'input' contém o comando digitado pelo usuário
// rl_clear_history() is not working in the ctrl+c case, we have a mem. leak
// TODO: treat sign ctrl+d to fix add_history leak above
// TODO: add_history nao salva se primeiro tiver espaco, porem salva se cmd for extenso

void	init_prompt(void)
{
	char	*input;

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
			if (input[0] != 32)
				add_history(input);
			printf("That's what she said: %s\n", input);
		}
		free(input);
		input = NULL;
	}
	rl_clear_history();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:38:38 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/15 22:17:50 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// add_history - Adiciona o comando à história se não estiver vazio
// apos utilizar a func a var 'input' contém o comando digitado pelo usuário
// rl_clear_history() is not working in the ctrl+c case, we have a mem. leak
// TODO: treat sign ctrl+d to fix add_history leak above
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
			add_history(input);
			printf("That's what she said: %s\n", input);
		}
		free(input);
		input = NULL;
	}
	rl_clear_history();
}

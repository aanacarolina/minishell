/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/22 21:51:19 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// TODO: verificar se precisa msg de erro ou so encerrar?
int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	(void)envp;
	if (argc != 1)
		return (1);
	//init_prompt();
	char **argzin;

	argzin = NULL;
    argzin[0] = "oie";
    argzin[1] = "tudo bem";
    ft_echo(argzin);
	return (0);
}

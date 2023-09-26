/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/25 21:26:47 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[])
{
	t_data	*argzins;

	//(void)argv;
	//(void)envp;
	if (argc < 1)
		return (1);
	// init_prompt();
	argzins = create_data_list(argc, argv);
	// print_list(argzins);
	ft_echo(argzins);
	return (0);
}

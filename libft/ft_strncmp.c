/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:00:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/25 21:45:07 by anacaro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	count;
	size_t	size;

	count = 0;
	size = len - 1;
	if (len == 0)
	{
		return (0);
	}
	while ((str1[count] == str2[count] && str1[count]
			!= '\0' && str2[count] != '\0') && count < size)
	{
		count++;
	}
	return ((unsigned char)str1[count] - (unsigned char)str2[count]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:44:35 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/15 21:33:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	count;
	int	size;

	size = ft_strlen(str);
	count = 0;
	if (count == size)
		return ((char *)str);
	while (count < size)
	{
		if (str[count] == (unsigned char)c)
			return ((char *)str + count);
		count++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

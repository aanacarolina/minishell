/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:37:55 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/24 16:29:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	words;
	int		count;

	words = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[count] != '\0')
	{
		if ((s[count] != c && s[count + 1] == c)
			|| (s[count] != c && s[count + 1] == '\0'))
			words++;
		count++;
	}
	return (words);
}

static char	**splits(char const *s, char c)
{
	char	**array;
	size_t	substr_len;
	int		i;

	array = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!array || !s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				substr_len = ft_strlen(s);
			else
				substr_len = ft_strchr(s, c) - s;
			array[i++] = ft_substr(s, 0, substr_len);
			s += substr_len;
		}
	}
	array[i] = NULL;
	return (array);
}

static char	**freearray(char const *s, char c, char **array)
{
	int		i;
	size_t	sizearray;
	size_t	nwords;

	nwords = countwords(s, c);
	sizearray = 0;
	while (array[sizearray] != NULL)
	{
		sizearray++;
	}
	i = 0;
	if (nwords != sizearray)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
	}
	if (!array)
		return (NULL);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = splits(s, c);
	freearray(s, c, array);
	return (array);
}

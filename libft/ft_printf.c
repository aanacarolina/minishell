/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:25 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/10 16:38:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		count_char;
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count_char = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count_char += ft_print_message(format[i], args);
		}
		else
			count_char += (int)write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count_char);
}

int	ft_print_message(char specifier, va_list args)
{
	if (specifier == 'c')
		return (printf_char(va_arg(args, int)));
	else if (specifier == 's')
		return (printf_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (printf_ptr(va_arg(args, unsigned long int), HEX_LOW));
	else if (specifier == 'd' || specifier == 'i')
		return (printf_nbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (printf_unsnbr(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (printf_nbrhex(va_arg(args, unsigned int), HEX_LOW));
	else if (specifier == 'X')
		return (printf_nbrhex(va_arg(args, unsigned int), HEX_UPPER));
	else if (specifier == '%')
		return ((int)write(1, "%", 1));
	else
		return ((int)write(1, "%", 1) + (int)write(1, &specifier, 1));
}

int	printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_str(char *str)
{
	int	count;
	int	count_char;

	count = 0;
	count_char = 0;
	if (!str)
		return ((int)write(1, "(null)", 6));
	while (str[count])
	{
		count_char += (int)write(1, &str[count], 1);
		count++;
	}
	return (count_char);
}

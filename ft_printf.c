/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarbaye <cdarbaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:55:11 by cdarbaye          #+#    #+#             */
/*   Updated: 2024/08/20 16:02:15 by cdarbaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = print_digit((va_arg(args, int)), 10, 'x');
	else if (c == 'c')
		count = print_char(va_arg(args, int));
	else if (c == 's')
		count = print_str(va_arg(args, char *));
	else if (c == 'x')
		count = print_digit((va_arg(args, unsigned int)), 16, 'x');
	else if (c == 'X')
		count = print_digit((va_arg(args, unsigned int)), 16, 'X');
	else if (c == 'p')
	{
		count = print_adress(va_arg(args, unsigned long long));
	}
	else if (c == 'u')
		count = print_udigit(va_arg(args, unsigned int));
	else if (c == '%')
		return (print_char('%'));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				count += check_format(args, str[++i]);
		}
		else
			count += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

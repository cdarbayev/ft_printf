/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarbaye <cdarbaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:55:21 by cdarbaye          #+#    #+#             */
/*   Updated: 2024/08/20 16:12:54 by cdarbaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base, char x_or_x)
{
	int		count;
	char	*symbols;

	if (x_or_x == 'X')
		symbols = "0123456789ABCDEF";
	else if (x_or_x == 'x' && base != 10)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, x_or_x) + 1);
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base, x_or_x);
		return (count + print_digit(n % base, base, x_or_x));
	}
}

int	print_udigit(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += print_udigit(n / 10);
		count += print_udigit(n % 10);
	}
	else
		count += print_char(n + 48);
	return (count);
}

int	print_adress(unsigned long n)
{
	char	string[25];
	int		count;
	char	*symbols;
	int		i;

	i = 0;
	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
	{
		count += 5;
		return (write(1, "(nil)", 5));
	}
	count = write(1, "0x", 2);
	while (n != 0)
	{
		string[i] = symbols[n % 16];
		n = n / 16;
		i++;
		count++;
	}
	while (i > 0)
		write(1, &string[(i--) - 1], 1);
	return (count);
}

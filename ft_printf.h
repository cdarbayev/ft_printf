/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarbaye <cdarbaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:55:35 by cdarbaye          #+#    #+#             */
/*   Updated: 2024/08/20 15:55:36 by cdarbaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

int			print_char(int c);
int			print_str(char *str);
int			print_digit(long n, int base, char x_or_x);
int			print_udigit(unsigned int n);
int			print_adress(unsigned long n);
int			ft_printf(const char *str, ...);

#endif
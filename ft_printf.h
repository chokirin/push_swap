/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:10:33 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/23 19:37:17 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int n);
int	ft_conversion(char c, va_list args);
int	print_hex(unsigned int n, char base);
int	print_ptr_hex(size_t n);
int	print_ptr(void *ptr);
int	print_unsigned(unsigned int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:24 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/27 17:04:34 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char base)
{
	int		count;
	char	*base_char;

	count = 0;
	if (base == 'x')
		base_char = "0123456789abcdef";
	else if (base == 'X')
		base_char = "0123456789ABCDEF";
	if (n >= 16)
	{
		count = print_hex((n / 16), base);
		return (count + print_hex(n % 16, base));
	}
	else
		return (ft_putchar(base_char[n]));
}

int	print_ptr(void *ptr)
{
	int	count;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		count = write(1, "0x", 2);
		return (count + print_ptr_hex((unsigned long)ptr));
	}
}

int	print_ptr_hex(size_t n)
{
	int		count;
	char	*base_char;

	base_char = "0123456789abcdef";
	if (n >= 16)
	{
		count = print_ptr_hex(n / 16);
		return (count + print_ptr_hex(n % 16));
	}
	return (ft_putchar(base_char[n]));
}

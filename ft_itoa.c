/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:11:14 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/03 17:00:06 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n = n * -1;
		res++;
	}
	if (n == 0)
		return (res + 1);
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{	
	int		len;
	char	*ptr;
	long	nbr;

	nbr = n;
	len = ft_len(nbr);
	ptr = malloc(sizeof(*ptr) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (nbr == 0)
		ptr[0] = '0';
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		ptr[len-- - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (ptr);
}

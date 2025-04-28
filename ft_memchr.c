/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:42:54 by xinzhang          #+#    #+#             */
/*   Updated: 2024/11/28 21:30:11 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t size)
{
	unsigned char	*p;
	unsigned char	target;

	p = (unsigned char *)ptr;
	target = (unsigned char)value;
	while (size > 0)
	{
		if (*p == target)
			return ((void *)p);
		p++;
		size--;
	}
	return (NULL);
}

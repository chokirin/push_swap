/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:33:30 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/03 15:50:55 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	unsigned char	*strptr;
	size_t			i;

	strptr = (unsigned char *)ptr;
	i = 0;
	while (i < count)
	{
		strptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

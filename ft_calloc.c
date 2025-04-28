/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:31:46 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/04 14:51:14 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_element, size_t element_size)
{
	void	*ptr;

	ptr = malloc(num_element * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, num_element * element_size);
	return (ptr);
}

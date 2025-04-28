/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:53:57 by xinzhang          #+#    #+#             */
/*   Updated: 2024/11/27 19:49:29 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (first[i] && second[i] && first[i] == second[i] && i < length)
	{
		i++;
	}
	if (i == length)
		return (0);
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

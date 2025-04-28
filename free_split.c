/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:05:30 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/23 18:16:36 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

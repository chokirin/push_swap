/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:20:20 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/04 15:43:21 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int character)
{
	if ((character >= '0' && character <= '9'))
		return (1);
	return (0);
}
/*
int	main()
{
	printf("%d\n", ft_isdigit('9'));
}*/

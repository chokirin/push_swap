/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:44 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/04 14:57:01 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	i;

	i = ft_strlen(str);
	while (i + 1 > 0)
	{
		if (str[i] == (char)chr)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

// char    *ft_strrchr(const char *str, int chr)
// {
// 	const char	*last;

// 	last = NULL;
// 	while (*str)
// 	{
// 		if (*str == (char)chr)
// 			last = str;
// 		str++;
// 	
// 	if (chr == '\0')
//     	return ((char *)str);
// 	if (last)
// 		return ((char *)last);
// 	return (NULL);
// }

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("teste", '\0'));

// }

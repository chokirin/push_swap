/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:35:34 by xinzhang          #+#    #+#             */
/*   Updated: 2024/12/03 21:27:25 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	char		*trimmed;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_isset(*s1, set))
		s1++;
	end = s1 + ft_strlen(s1) -1;
	while (end > s1 && ft_isset(*end, set))
	{
		end--;
	}
	if (end < s1)
	{
		return (ft_strdup(""));
	}
	trimmed = malloc(end - s1 + 2);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1, end - s1 + 2);
	trimmed[end - s1 + 1] = '\0';
	return (trimmed);
}

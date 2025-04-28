/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:38 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/23 17:06:39 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_to_tab(char const *str, int start, int end)
{
	int		i;
	char	*tbl;

	i = 0;
	tbl = malloc(sizeof(char) * (end - start + 1));
	if (tbl == NULL)
		return (tbl);
	while (start < end)
	{
		tbl[i] = str[start];
		i++;
		start++;
	}
	tbl[i] = '\0';
	return (tbl);
}

static void	*do_split(char **result, char const *s, char c)
{
	int	tab_idx;
	int	i;
	int	start;

	i = 0;
	tab_idx = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			result[tab_idx] = put_to_tab(s, start, i);
			if (result[tab_idx] == NULL)
				return (free_split(result, tab_idx), NULL);
			tab_idx++;
		}
	}
	result[tab_idx] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	if (!do_split(result, s, c))
		return (NULL);
	return (result);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char **tbl;
	int i = 0;
	if (ac == 2)
	{
		tbl = ft_split(av[1], '|');
		while (tbl[i] != NULL)
		{
			printf("%s\n", tbl[i]);
			i++;
		}
	}
	return 0;
}
*/
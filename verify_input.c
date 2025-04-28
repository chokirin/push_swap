/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:46:48 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/24 18:38:28 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

int	is_int(const char *str)
{
	int		i;
	long	num;
	int		is_negative;

	i = 0;
	is_negative = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative = -is_negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	num = num * is_negative;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_duplicate(char **data_list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(data_list[i]) == ft_atoi(data_list[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	verify_input(char **data_list, int size, int nd_free)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_int(data_list[i]) || !is_integer(data_list[i])
			|| is_duplicate(data_list, size))
		{
			write(2, "Error\n", 7);
			if (nd_free == 2)
				free_split(data_list, size);
			exit(0);
		}
		i++;
	}
}

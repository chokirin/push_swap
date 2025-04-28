/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:46:28 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/25 19:34:53 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("error");
		exit (0);
	}
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
	{
		ft_printf("error");
		free(stack);
		exit (0);
	}
	stack->size = size;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i - 1] > stack->data[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_index(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	min_rotation(int index, int size)
{
	if (index <= size - index)
		return (index);
	else
		return (index - size);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

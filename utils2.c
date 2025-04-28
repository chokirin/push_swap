/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:46:41 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/25 17:23:38 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	min = stack->data[0];
	i = 0;
	while (++i < stack->size)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->data[0];
	i = 0;
	while (++i < stack->size)
	{
		if (stack->data[i] > max)
			max = stack->data[i];
	}
	return (max);
}

int	find_median(t_stack *stack, int candidat)
{
	int	sc;
	int	gc;
	int	i;

	while (1)
	{
		sc = 0;
		gc = 0;
		i = 0;
		while (i < stack->size)
		{
			if (stack->data[i] < candidat)
				sc++;
			else if (stack->data[i] > candidat)
				gc++;
			i++;
		}
		if ((sc - gc) >= -1 && (sc - gc) <= 1)
			return (candidat);
		if (sc > gc)
			candidat--;
		else
			candidat++;
	}
}

void	rotate_each(t_stack *a, t_stack *b, int ra, int rb)
{
	while (ra > 0)
	{
		rotate_up(a, "ra");
		ra--;
	}
	while (ra < 0)
	{
		rotate_down(a, "rra");
		ra++;
	}
	while (rb > 0)
	{
		rotate_up(b, "rb");
		rb--;
	}
	while (rb < 0)
	{
		rotate_down(b, "rrb");
		rb++;
	}
}

void	min_to_top(t_stack *stack)
{
	int	roll_up;
	int	roll_down;

	roll_up = get_index(stack, find_min(stack));
	roll_down = stack->size - get_index(stack, find_max(stack)) - 1;
	if (roll_up < roll_down)
	{
		while (roll_up--)
			rotate_up(stack, "ra");
	}
	else
	{
		while (roll_down--)
			rotate_down(stack, "rra");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:46:22 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/25 17:17:11 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->data[0] > stack->data[1] && stack->data[1] > stack->data[2])
	{
		swap(stack, "sa");
		rotate_down(stack, "rra");
	}
	else if (stack->data[0] > stack->data[2] && stack->data[2] > stack->data[1])
		rotate_up(stack, "ra");
	else if (stack->data[1] > stack->data[0] && stack->data[0] > stack->data[2])
		rotate_down(stack, "rra");
	else if (stack->data[2] > stack->data[0] && stack->data[0] > stack->data[1])
		swap(stack, "sa");
	else if (stack->data[1] > stack->data[2] && stack->data[2] > stack->data[0])
	{
		swap(stack, "sa");
		rotate_up(stack, "ra");
	}
}

int	get_cost(t_stack *a, int num)
{
	int	i;
	int	size;
	int	temp;

	i = 0;
	size = a->size;
	if (num < find_min(a) || num > find_max(a))
	{
		return (min_rotation(get_index(a, find_min(a)), size));
	}
	while (i < size)
	{
		temp = a->data[(i - 1 + size) % size];
		if (num < a->data[i] && num > temp)
			return (min_rotation(i, size));
		i++;
	}
	return (-1);
}

int	best_index(t_stack *a, t_stack *b)
{
	int	i;
	int	best_cost;
	int	best_index;
	int	temp;

	best_cost = ft_abs(get_cost(a, b->data[0]));
	best_index = 0;
	i = 1;
	while (i < ft_abs(best_cost) && i < b->size)
	{
		temp = ft_abs(get_cost(a, b->data[i]));
		if (temp < best_cost - i)
		{
			best_cost = temp + i;
			best_index = i;
		}
		temp = ft_abs(get_cost(a, b->data[b->size - i]));
		if (temp < best_cost - i)
		{
			best_cost = temp + i;
			best_index = b->size - i;
		}
		i++;
	}
	return (best_index);
}

void	push_back(t_stack *a, t_stack *b, int index)
{
	int	rotate_a;
	int	rotate_b;
	int	rotate_ab;

	rotate_a = get_cost(a, b->data[index]);
	rotate_b = min_rotation(index, b->size);
	rotate_ab = 0;
	while (rotate_a != 0 && rotate_b != 0 && rotate_a * rotate_b > 0)
	{
		if (rotate_a > 0)
		{
			rotate_ab++;
			rotate_a--;
			rotate_b--;
		}
		else
		{
			rotate_ab--;
			rotate_a++;
			rotate_b++;
		}
	}
	rotate_both(a, b, rotate_ab);
	rotate_each(a, b, rotate_a, rotate_b);
	push(b, a, "pa");
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	int	median;
	int	i;

	i = 0;
	median = find_median(a, (find_min(a) + find_max(a)) / 2);
	while (i < size - 3)
	{
		push(a, b, "pb");
		if (b->data[0] > median && i > 2)
			rotate_up(b, "rb");
		i++;
	}
	sort_3(a);
	while (b->size > 0)
	{
		push_back(a, b, best_index(a, b));
	}
	min_to_top(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:46:13 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/24 17:01:41 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *from, t_stack *to, char *msg)
{
	rotate_up(from, NULL);
	to->data[to->size++] = from->data[--from->size];
	rotate_down(to, NULL);
	ft_printf("%s\n", msg);
}

void	swap(t_stack *stack, char *msg)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
	ft_printf("%s\n", msg);
}

void	rotate_down(t_stack *stack, char *msg)
{
	int	bottom;
	int	i;

	if (stack->size < 2)
		return ;
	bottom = stack->data[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = bottom;
	if (msg != NULL)
		ft_printf("%s\n", msg);
}

void	rotate_up(t_stack *stack, char *msg)
{
	int	top;
	int	i;

	if (stack->size < 2)
		return ;
	top = stack->data[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->size - 1] = top;
	if (msg != NULL)
		ft_printf("%s\n", msg);
}

void	rotate_both(t_stack *a, t_stack *b, int direc)
{
	while (direc > 0)
	{
		rotate_up(a, NULL);
		rotate_up(b, NULL);
		ft_printf("rr\n");
		direc--;
	}
	while (direc < 0)
	{
		rotate_down(a, NULL);
		rotate_down(b, NULL);
		ft_printf("rrr\n");
		direc++;
	}
}
